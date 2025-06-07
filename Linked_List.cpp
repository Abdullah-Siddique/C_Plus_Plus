#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
    string address;
    Contact* next;
    Contact* prev;

    Contact(string n, string p, string e, string a) : name(n), phone(p), email(e), address(a), next(nullptr), prev(nullptr) {}
};

class ContactManager {
private:
    Contact* head;
    Contact* tail;

    bool isValidPhone(const string& phone) {
        if (phone.length() != 10) return false;
        for (char c : phone) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    string toLowerCase(const string& str) {
        string result = str;
        for (char& c : result) {
            c = tolower(c);
        }
        return result;
    }

public:
    ContactManager() : head(nullptr), tail(nullptr) {}

    void addContact(string name, string phone, string email, string address) {
        if (!isValidPhone(phone)) {
            cout << "Invalid phone number! Must be 10 digits.\n";
            return;
        }

        Contact* newContact = new Contact(name, phone, email, address);

        if (!head) {
            head = tail = newContact;
        } else {
            Contact* current = head;
            Contact* prev = nullptr;

            while (current && toLowerCase(current->name) < toLowerCase(name)) {
                prev = current;
                current = current->next;
            }

            if (!prev) {
                newContact->next = head;
                head->prev = newContact;
                head = newContact;
            } else if (!current) {
                tail->next = newContact;
                newContact->prev = tail;
                tail = newContact;
            } else {
                newContact->next = current;
                newContact->prev = current->prev;
                current->prev->next = newContact;
                current->prev = newContact;
            }
        }
        cout << "Contact added successfully!\n";
        saveToFile("contacts.html");
        saveToTextFile("contacts.txt");
    }

    void viewContacts() {
        if (!head) {
            cout << "No contacts available.\n";
            return;
        }

        Contact* current = head;
        cout << "\n--- Contact List ---\n";
        while (current) {
            cout << "Name: " << current->name << "\n";
            cout << "Phone: " << current->phone << "\n";
            cout << "Email: " << current->email << "\n";
            cout << "Address: " << current->address << "\n";
            cout << "-------------------\n";
            current = current->next;
        }
    }

    void searchContact(string key, bool byName = true) {
        Contact* current = head;
        bool found = false;
        key = toLowerCase(key);

        while (current) {
            if ((byName && toLowerCase(current->name) == key) || (!byName && current->phone == key)) {
                cout << "\n--- Contact Found ---\n";
                cout << "Name: " << current->name << "\n";
                cout << "Phone: " << current->phone << "\n";
                cout << "Email: " << current->email << "\n";
                cout << "Address: " << current->address << "\n";
                cout << "-------------------\n";
                found = true;
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Contact not found!\n";
        }
    }

    void deleteContact(string key, bool byName = true) {
        Contact* current = head;
        key = toLowerCase(key);

        while (current) {
            if ((byName && toLowerCase(current->name) == key) || (!byName && current->phone == key)) {
                if (current == head) {
                    head = current->next;
                    if (head) head->prev = nullptr;
                    else tail = nullptr;
                } else if (current == tail) {
                    tail = current->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                cout << "Contact deleted successfully!\n";
                saveToFile("contacts.html");
                saveToTextFile("contacts.txt");
                return;
            }
            current = current->next;
        }
        cout << "Contact not found!\n";
    }

    void updateContact(string name) {
        Contact* current = head;
        name = toLowerCase(name);

        while (current) {
            if (toLowerCase(current->name) == name) {
                string newName, phone, email, address;
                cout << "Enter new name (or press Enter to keep '" << current->name << "'): ";
                cin.ignore();
                getline(cin, newName);
                cout << "Enter new phone (or press Enter to keep '" << current->phone << "'): ";
                getline(cin, phone);
                cout << "Enter new email (or press Enter to keep '" << current->email << "'): ";
                getline(cin, email);
                cout << "Enter new address (or press Enter to keep '" << current->address << "'): ";
                getline(cin, address);

                if (!newName.empty()) current->name = newName;
                if (!phone.empty()) {
                    if (isValidPhone(phone)) current->phone = phone;
                    else {
                        cout << "Invalid phone number! Update aborted.\n";
                        return;
                    }
                }
                if (!email.empty()) current->email = email;
                if (!address.empty()) current->address = address;

                cout << "Contact updated successfully!\n";
                saveToFile("contacts.html");
                saveToTextFile("contacts.txt");
                return;
            }
            current = current->next;
        }
        cout << "Contact not found!\n";
    }

    void sortByPhone() {
        if (!head || !head->next) return;

        bool swapped;
        do {
            swapped = false;
            Contact* current = head;
            while (current->next) {
                if (current->phone > current->next->phone) {
                    swap(current->name, current->next->name);
                    swap(current->phone, current->next->phone);
                    swap(current->email, current->next->email);
                    swap(current->address, current->next->address);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
        cout << "Contacts sorted by phone number!\n";
        saveToFile("contacts.html");
        saveToTextFile("contacts.txt");
    }

    void saveToTextFile(const string& filename) {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "Error opening file for writing!\n";
            return;
        }

        Contact* current = head;
        while (current) {
            outFile << current->name << "\n";
            outFile << current->phone << "\n";
            outFile << current->email << "\n";
            outFile << current->address << "\n";
            outFile << "----\n";
            current = current->next;
        }
        outFile.close();
        cout << "Contacts saved to " << filename << "!\n";
    }

    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "Error opening file for writing!\n";
            return;
        }

        outFile << "<!DOCTYPE html>\n";
        outFile << "<html lang=\"en\">\n";
        outFile << "<head>\n";
        outFile << "<meta charset=\"UTF-8\">\n";
        outFile << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
        outFile << "<title>Contact Manager</title>\n";
        outFile << "<style>\n";
        outFile << "* { margin: 0; padding: 0; box-sizing: border-box; }\n";
        outFile << "body { font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); min-height: 100vh; padding: 20px; color: #333; }\n";
        outFile << ".container { max-width: 1200px; margin: 0 auto; background: rgba(255, 255, 255, 0.95); backdrop-filter: blur(10px); border-radius: 20px; box-shadow: 0 20px 40px rgba(0,0,0,0.1); overflow: hidden; }\n";
        outFile << ".header { background: linear-gradient(135deg, #4facfe 0%, #00f2fe 100%); padding: 30px; text-align: center; color: white; }\n";
        outFile << ".header h1 { font-size: 2.5rem; font-weight: 700; margin-bottom: 10px; text-shadow: 0 2px 4px rgba(0,0,0,0.3); }\n";
        outFile << ".header p { font-size: 1.1rem; opacity: 0.9; }\n";
        outFile << ".content { padding: 40px; }\n";
        outFile << ".table-container { overflow-x: auto; border-radius: 15px; box-shadow: 0 10px 30px rgba(0,0,0,0.1); }\n";
        outFile << "table { width: 100%; border-collapse: collapse; background: white; font-size: 16px; }\n";
        outFile << "th { background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); color: white; padding: 20px 15px; text-align: left; font-weight: 600; text-transform: uppercase; letter-spacing: 1px; position: sticky; top: 0; z-index: 10; }\n";
        outFile << "td { padding: 18px 15px; border-bottom: 1px solid #e0e6ed; transition: all 0.3s ease; }\n";
        outFile << "tr:hover { background: linear-gradient(135deg, #f8f9ff 0%, #e8f4fd 100%); transform: translateY(-2px); box-shadow: 0 5px 15px rgba(0,0,0,0.1); }\n";
        outFile << "tr:nth-child(even) { background: #f8fafc; }\n";
        outFile << "tr:nth-child(even):hover { background: linear-gradient(135deg, #f0f7ff 0%, #e0f2fe 100%); }\n";
        outFile << ".contact-name { font-weight: 600; color: #2563eb; }\n";
        outFile << ".contact-phone { color: #059669; font-weight: 500; }\n";
        outFile << ".contact-email { color: #7c3aed; }\n";
        outFile << ".contact-address { color: #dc2626; }\n";
        outFile << ".stats { display: flex; justify-content: center; margin-bottom: 30px; gap: 20px; flex-wrap: wrap; }\n";
        outFile << ".stat-card { background: linear-gradient(135deg, #a8edea 0%, #fed6e3 100%); padding: 20px; border-radius: 15px; text-align: center; min-width: 150px; box-shadow: 0 8px 25px rgba(0,0,0,0.1); }\n";
        outFile << ".stat-number { font-size: 2rem; font-weight: bold; color: #2563eb; }\n";
        outFile << ".stat-label { color: #64748b; font-weight: 500; margin-top: 5px; }\n";
        outFile << "footer { background: linear-gradient(135deg, #2d3748 0%, #4a5568 100%); color: white; padding: 40px; text-align: center; }\n";
        outFile << ".footer-content { max-width: 800px; margin: 0 auto; }\n";
        outFile << ".footer-title { font-size: 1.5rem; font-weight: 700; margin-bottom: 20px; color: #e2e8f0; }\n";
        outFile << ".footer-info { display: flex; justify-content: space-around; flex-wrap: wrap; gap: 20px; margin-bottom: 30px; }\n";
        outFile << ".footer-section h4 { color: #4facfe; margin-bottom: 10px; font-weight: 600; }\n";
        outFile << ".footer-section p { color: #cbd5e0; line-height: 1.6; }\n";
        outFile << ".footer-section a { color: #4facfe; text-decoration: none; font-weight: 500; transition: all 0.3s ease; }\n";
        outFile << ".footer-section a:hover { color: #00f2fe; text-shadow: 0 0 10px rgba(79, 172, 254, 0.5); }\n";
        outFile << ".footer-bottom { border-top: 1px solid #4a5568; padding-top: 20px; color: #a0aec0; }\n";
        outFile << "@media (max-width: 768px) {\n";
        outFile << "  body { padding: 10px; }\n";
        outFile << "  .header h1 { font-size: 2rem; }\n";
        outFile << "  .content { padding: 20px; }\n";
        outFile << "  .stats { gap: 10px; }\n";
        outFile << "  .stat-card { min-width: 120px; padding: 15px; }\n";
        outFile << "  th, td { padding: 12px 8px; font-size: 14px; }\n";
        outFile << "  .footer-info { flex-direction: column; text-align: center; }\n";
        outFile << "}\n";
        outFile << "@media (max-width: 480px) {\n";
        outFile << "  .header h1 { font-size: 1.8rem; }\n";
        outFile << "  .stat-card { min-width: 100px; }\n";
        outFile << "  th, td { padding: 10px 6px; font-size: 13px; }\n";
        outFile << "  .table-container { margin: 0 -10px; }\n";
        outFile << "}\n";
        outFile << "</style>\n";
        outFile << "</head>\n";
        outFile << "<body>\n";
        outFile << "<div class=\"container\">\n";
        outFile << "<div class=\"header\">\n";
        outFile << "<h1>📱 Contact Manager</h1>\n";
        outFile << "<p>Your Personal Contact Directory</p>\n";
        outFile << "</div>\n";
        outFile << "<div class=\"content\">\n";

        int totalContacts = 0;
        Contact* current = head;
        while (current) {
            totalContacts++;
            current = current->next;
        }

        outFile << "<div class=\"stats\">\n";
        outFile << "<div class=\"stat-card\">\n";
        outFile << "<div class=\"stat-number\">" << totalContacts << "</div>\n";
        outFile << "<div class=\"stat-label\">Total Contacts</div>\n";
        outFile << "</div>\n";
        outFile << "</div>\n";

        if (totalContacts > 0) {
            outFile << "<div class=\"table-container\">\n";
            outFile << "<table>\n";
            outFile << "<thead>\n";
            outFile << "<tr>\n";
            outFile << "<th>👤 Name</th>\n";
            outFile << "<th>📞 Phone</th>\n";
            outFile << "<th>📧 Email</th>\n";
            outFile << "<th>🏠 Address</th>\n";
            outFile << "</tr>\n";
            outFile << "</thead>\n";
            outFile << "<tbody>\n";

            current = head;
            while (current) {
                outFile << "<tr>\n";
                outFile << "<td class=\"contact-name\">" << current->name << "</td>\n";
                outFile << "<td class=\"contact-phone\">" << current->phone << "</td>\n";
                outFile << "<td class=\"contact-email\">" << current->email << "</td>\n";
                outFile << "<td class=\"contact-address\">" << current->address << "</td>\n";
                outFile << "</tr>\n";
                current = current->next;
            }

            outFile << "</tbody>\n";
            outFile << "</table>\n";
            outFile << "</div>\n";
        } else {
            outFile << "<div style=\"text-align: center; padding: 60px 20px; color: #64748b;\">\n";
            outFile << "<h3>No contacts available</h3>\n";
            outFile << "<p>Add some contacts to see them here!</p>\n";
            outFile << "</div>\n";
        }

        outFile << "</div>\n";
        outFile << "</div>\n";
        outFile << "<footer>\n";
        outFile << "<div class=\"footer-content\">\n";
        outFile << "<div class=\"footer-title\">Contact Manager</div>\n";
        outFile << "<div class=\"footer-info\">\n";
        outFile << "<div class=\"footer-section\">\n";
        outFile << "<h4>Authority</h4>\n";
        outFile << "<p>Abdullah Siddique</p>\n";
        outFile << "</div>\n";
        outFile << "<div class=\"footer-section\">\n";
        outFile << "<h4>Contact</h4>\n";
        outFile << "<p>siddiqueabdullah581@gmail.com</p>\n";
        outFile << "</div>\n";
        outFile << "<div class=\"footer-section\">\n";
        outFile << "<h4>GitHub</h4>\n";
        outFile << "<p><a href=\"https://github.com/Abdullah-Siddique\" target=\"_blank\">Abdullah Siddique</a></p>\n";
        outFile << "</div>\n";
        outFile << "</div>\n";
        outFile << "<div class=\"footer-bottom\">\n";
        outFile << "<p>© 2025 Contact Manager. All rights reserved.</p>\n";
        outFile << "</div>\n";
        outFile << "</div>\n";
        outFile << "</footer>\n";
        outFile << "</body>\n";
        outFile << "</html>\n";
        outFile.close();
        cout << "Contacts saved to " << filename << "!\n";
    }

    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "No existing contact file found.\n";
            return;
        }

        string name, phone, email, address, delimiter;
        while (getline(inFile, name)) {
            if (!getline(inFile, phone) || !getline(inFile, email) || !getline(inFile, address) || !getline(inFile, delimiter) || delimiter != "----") {
                break;
            }
            if (!name.empty() && !phone.empty()) {
                addContact(name, phone, email, address);
            }
        }
        inFile.close();
        cout << "Contacts loaded from " << filename << "!\n";
    }

    ~ContactManager() {
        Contact* current = head;
        while (current) {
            Contact* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

void displayMenu() {
    cout << "\n=== Personal Contact Manager ===\n";
    cout << "1. Add Contact\n";
    cout << "2. View All Contacts\n";
    cout << "3. Search Contact by Name\n";
    cout << "4. Search Contact by Phone\n";
    cout << "5. Delete Contact by Name\n";
    cout << "6. Delete Contact by Phone\n";
    cout << "7. Update Contact by Name\n";
    cout << "8. Sort Contacts by Phone\n";
    cout << "9. Save Contacts to File\n";
    cout << "10. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    ContactManager cm;
    cm.loadFromFile("contacts.txt");
    int choice;
    string name, phone, email, address;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone (10 digits): ";
                getline(cin, phone);
                cout << "Enter email: ";
                getline(cin, email);
                cout << "Enter address: ";
                getline(cin, address);
                cm.addContact(name, phone, email, address);
                break;

            case 2:
                cm.viewContacts();
                break;

            case 3:
                cout << "Enter name to search: ";
                getline(cin, name);
                cm.searchContact(name, true);
                break;

            case 4:
                cout << "Enter phone number to search: ";
                getline(cin, phone);
                cm.searchContact(phone, false);
                break;

            case 5:
                cout << "Enter name to delete: ";
                getline(cin, name);
                cm.deleteContact(name, true);
                break;

            case 6:
                cout << "Enter phone number to delete: ";
                getline(cin, phone);
                cm.deleteContact(phone, false);
                break;

            case 7:
                cout << "Enter name of contact to update: ";
                getline(cin, name);
                cm.updateContact(name);
                break;

            case 8:
                cm.sortByPhone();
                break;

            case 9:
                cm.saveToFile("contacts.html");
                cm.saveToTextFile("contacts.txt");
                break;

            case 10:
                cout << "Exiting and saving contacts...\n";
                cm.saveToFile ("contacts.html");
                cm.saveToTextFile("contacts.txt");
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
