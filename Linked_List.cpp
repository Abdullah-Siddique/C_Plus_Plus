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
    }

    void saveToFile(const string& filename) {
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
            current = current->next;
        }
        outFile.close();
        cout << "Contacts saved to " << filename << "!\n";
    }

    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "No existing contact file found.\n";
            return;
        }

        string name, phone, email, address;
        while (getline(inFile, name) && getline(inFile, phone) && getline(inFile, email) && getline(inFile, address)) {
            addContact(name, phone, email, address);
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
                cm.saveToFile("contacts.txt");
                break;

            case 10:
                cout << "Exiting and saving contacts...\n";
                cm.saveToFile("contacts.txt");
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
