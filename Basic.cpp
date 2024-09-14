#include <iostream>  // Include the input-output stream library
#include <string>    // Include the string library for string manipulation
using namespace std; // Use the standard namespace

// Function to add two integers
int add(int a, int b) {
    return a + b; // Return the sum of a and b
}

// Function to greet a user
void greetUser(string name) {
    cout << "Hello, " << name << "!" << endl; // Print a greeting message
}

// Function to calculate the factorial of a number (recursive function)
int factorial(int n) {
    if (n <= 1) {
        return 1; // Base case: factorial of 1 or 0 is 1
    } else {
        return n * factorial(n - 1); // Recursive case: n * factorial of (n-1)
    }
}

// Function to demonstrate basic input and output
void demonstrateIO() {
    int age;
    string name;
    
    // Prompt the user for their name and age
    cout << "Enter your name: ";
    cin >> name; // Get the user's name
    cout << "Enter your age: ";
    cin >> age; // Get the user's age
    
    // Print a message using the provided name and age
    cout << "Hello, " << name << "! You are " << age << " years old." << endl;
}

// Base class: Person
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {} // Constructor with initialization list

    // Virtual function to display information (polymorphism)
    virtual void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class: Student (inherits from Person)
class Student : public Person {
private:
    string studentID;
public:
    Student(string n, int a, string id) : Person(n, a), studentID(id) {} // Constructor

    // Override the displayInfo function
    void displayInfo() override {
        cout << "Name: " << name << ", Age: " << age << ", Student ID: " << studentID << endl;
    }
};

// Derived class: Teacher (inherits from Person)
class Teacher : public Person {
private:
    string subject;
public:
    Teacher(string n, int a, string subj) : Person(n, a), subject(subj) {} // Constructor

    // Override the displayInfo function
    void displayInfo() override {
        cout << "Name: " << name << ", Age: " << age << ", Subject: " << subject << endl;
    }
};

// Main function - the starting point of the program
int main() {
    // Print a welcome message
    cout << "Welcome to the C++ program!" << endl;
    
    // Demonstrate basic input and output
    demonstrateIO();
    
    // Demonstrate the add function
    int result = add(3, 4); // Call the add function with arguments 3 and 4
    cout << "The sum of 3 and 4 is: " << result << endl; // Print the result
    
    // Demonstrate the greetUser function
    greetUser("Alice"); // Call the greetUser function with the name "Alice"
    
    // Demonstrate the factorial function
    int factResult = factorial(5); // Call the factorial function with the argument 5
    cout << "The factorial of 5 is: " << factResult << endl; // Print the result
    
    // Using a for loop to print numbers from 1 to 5
    cout << "Numbers from 1 to 5: ";
    for (int i = 1; i <= 5; ++i) {
        cout << i << " "; // Print the current value of i
    }
    cout << endl; // Print a new line
    
    // Using a while loop to print numbers from 5 to 1
    cout << "Numbers from 5 to 1: ";
    int j = 5;
    while (j > 0) {
        cout << j << " "; // Print the current value of j
        --j; // Decrease the value of j by 1
    }
    cout << endl; // Print a new line
    
    // Using a do-while loop to ensure the loop runs at least once
    int num;
    do {
        cout << "Enter a number (0 to exit): ";
        cin >> num; // Get a number from the user
        if (num != 0) {
            cout << "You entered: " << num << endl; // Print the number
        }
    } while (num != 0); // Continue the loop until the user enters 0
    
    // Create objects of Person, Student, and Teacher classes
    Person p1("John Doe", 30);
    Student s1("Jane Smith", 20, "S12345");
    Teacher t1("Dr. Brown", 50, "Physics");

    // Use polymorphism to display information
    Person* people[3] = { &p1, &s1, &t1 };

    for (int i = 0; i < 3; ++i) {
        people[i]->displayInfo(); // Call the appropriate displayInfo function
    }

    // End of the program
    cout << "Goodbye!" << endl;
    return 0; // Return 0 to indicate successful execution
}

