#include <iostream>
#include <string>
#include <vector>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

double multiply(double a, double b) {
    return a * b;
}

inline int square(int x) {
    return x * x;
}

int factorial(int n) {
    if (n <= 1) return 1;
    else return n * factorial(n - 1);
}

void printMessage(string message, int times = 1) {
    for (int i = 0; i < times; ++i) {
        cout << message << endl;
    }
}

void increment(int &n) {
    ++n;
}

auto addLambda = [](int a, int b) {
    return a + b;
};

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

typedef int (*operation)(int, int);

int subtract(int a, int b) {
    return a - b;
}

operation getOperation(char op) {
    if (op == '+') return add;
    else if (op == '-') return subtract;
    else return nullptr;
}

int main() {
    int sum = add(3, 4);
    cout << "Sum: " << sum << endl;

    cout << "Product (int): " << multiply(3, 4) << endl;
    cout << "Product (double): " << multiply(2.5, 4.2) << endl;

    cout << "Square: " << square(5) << endl;

    cout << "Factorial: " << factorial(5) << endl;

    printMessage("Hello", 3);
    printMessage("World");

    int num = 10;
    increment(num);
    cout << "Incremented: " << num << endl;

    cout << "Lambda Sum: " << addLambda(5, 6) << endl;

    cout << "Maximum (int): " << maximum(3, 7) << endl;
    cout << "Maximum (double): " << maximum(5.3, 2.4) << endl;

    operation op = getOperation('+');
    if (op != nullptr) {
        cout << "Operation Result: " << op(10, 5) << endl;
    }

    return 0;
}
