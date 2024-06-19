#include <iostream>
using namespace std;

class Boy {
public:
    int age;
    int roll;
    string name;

    void setData(int a, int r, string n) {
        age = a;
        roll = r;
        name = n;
    }

    void displayData() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll: " << roll << endl;
    }
};

class Student : public Boy {
public:
    int id;

    void setId(int i) {
        id = i;
    }

    void displayId() {
        cout << "Id: " << id << endl;
    }
};

int main() {
    Student Abdullah;

    // Taking input
    cout << "Enter name: ";
    cin >> Abdullah.name;
    cout << "Enter age: ";
    cin >> Abdullah.age;
    cout << "Enter roll: ";
    cin >> Abdullah.roll;
    cout << "Enter id: ";
    cin >> Abdullah.id;

    // Displaying data
    Abdullah.displayData();
    Abdullah.displayId();

    return 0;
}
