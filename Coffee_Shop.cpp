#include <bits/stdc++.h> 
using namespace std;

struct MenuItem {
    string name;
    double price;
};

class CoffeeShop {
private:
    vector<MenuItem> menu;
    vector<MenuItem> order;
    vector<vector<MenuItem>> orderHistory;
    double totalBill;
    int rewardPoints;
    MenuItem dailySpecial;

public:
    CoffeeShop();
    void displayMenu();
    void takeOrder();
    void displayBill();
    void displayOrderHistory();
    void addCustomOrder();
    void applyPromotion();
    void displayRewards();
};

CoffeeShop::CoffeeShop() {
    menu = {
        {"Espresso", 2.50},
        {"Cappuccino", 3.00},
        {"Latte", 3.50},
        {"Mocha", 4.00},
        {"Americano", 2.75}
    };
    totalBill = 0.0;
    rewardPoints = 0;
    dailySpecial = menu[rand() % menu.size()];
    dailySpecial.price *= 0.9;
}

void CoffeeShop::displayMenu() {
    cout << "\nWelcome to the Coffee Shop!" << endl;
    cout << "Here is our menu:" << endl;
    for (size_t i = 0; i < menu.size(); ++i) {
        cout << i + 1 << ". " << menu[i].name << " - $" << fixed << setprecision(2) << menu[i].price;
        if (menu[i].name == dailySpecial.name) {
            cout << " (Daily Special: 10% OFF!)";
        }
        cout << endl;
    }
}

void CoffeeShop::takeOrder() {
    int choice;
    char orderMore;

    do {
        cout << "Please enter the number of the item you would like to order: ";
        cin >> choice;

        if (choice > 0 && choice <= menu.size()) {
            order.push_back(menu[choice - 1]);
            totalBill += menu[choice - 1].price;
            cout << "Added " << menu[choice - 1].name << " to your order." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Would you like to order anything else? (y/n): ";
        cin >> orderMore;

    } while (orderMore == 'y' || orderMore == 'Y');

    orderHistory.push_back(order);
    rewardPoints += static_cast<int>(totalBill) / 5;
}

void CoffeeShop::displayBill() {
    cout << "\nYour order summary:" << endl;
    for (const auto& item : order) {
        cout << item.name << " - $" << fixed << setprecision(2) << item.price << endl;
    }
    cout << "Total Bill: $" << fixed << setprecision(2) << totalBill << endl;

    if (rewardPoints >= 10) {
        cout << "Congratulations! You have enough reward points to redeem a $5 discount!" << endl;
        cout << "Do you want to redeem your points? (y/n): ";
        char redeem;
        cin >> redeem;
        if (redeem == 'y' || redeem == 'Y') {
            totalBill -= 5.0;
            rewardPoints -= 10;
            cout << "Your updated total bill is: $" << fixed << setprecision(2) << totalBill << endl;
        }
    }

    cout << "Thank you for visiting our coffee shop!" << endl;
    order.clear();
    totalBill = 0.0;
}

void CoffeeShop::displayOrderHistory() {
    cout << "\nYour Order History:" << endl;
    if (orderHistory.empty()) {
        cout << "No orders yet!" << endl;
        return;
    }
    for (size_t i = 0; i < orderHistory.size(); ++i) {
        cout << "Order " << i + 1 << ":" << endl;
        for (const auto& item : orderHistory[i]) {
            cout << "- " << item.name << " - $" << fixed << setprecision(2) << item.price << endl;
        }
    }
}

void CoffeeShop::addCustomOrder() {
    string customName;
    double customPrice;

    cout << "\nEnter the name of your custom coffee: ";
    cin.ignore();
    getline(cin, customName);

    cout << "Enter the price for your custom coffee: $";
    cin >> customPrice;

    menu.push_back({customName, customPrice});
    cout << customName << " has been added to the menu!" << endl;
}

void CoffeeShop::applyPromotion() {
    cout << "\nSpecial Promotion! Buy 1 Get 1 Free on selected items!" << endl;
    cout << "Selected item: " << menu[0].name << endl;
}

void CoffeeShop::displayRewards() {
    cout << "\nYou have " << rewardPoints << " reward points." << endl;
    cout << "Earn 10 points to redeem a $5 discount!" << endl;
}

int main() {
    CoffeeShop shop;
    int choice;

    do {
        cout << "\nWelcome to the Coffee Shop!" << endl;
        cout << "1. View Menu" << endl;
        cout << "2. Place an Order" << endl;
        cout << "3. View Order History" << endl;
        cout << "4. Add a Custom Coffee" << endl;
        cout << "5. Check Rewards" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            shop.displayMenu();
            break;
        case 2:
            shop.takeOrder();
            shop.displayBill();
            break;
        case 3:
            shop.displayOrderHistory();
            break;
        case 4:
            shop.addCustomOrder();
            break;
        case 5:
            shop.displayRewards();
            break;
        case 6:
            cout << "Goodbye! Thank you for visiting!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
