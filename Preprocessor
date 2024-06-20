#include <iostream>
#include <cmath> 

// 1. Define Constants
#define PI 3.14159
#define EULER 2.71828

// 2. Macro Functions
#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))

// 3. Conditional Compilation
#define DEBUG

// 4. File Inclusion
#include <string>

// 5. Inline Code with Preprocessor
#define PRINT_VAR(var) std::cout << #var << " = " << var << std::endl

// 6. Stringizing Operator
#define TO_STRING(x) #x

// 7. Token Pasting
#define MAKE_UNIQUE(name) name##__LINE__

// 8. Undefining Macros
#undef EULER
#define EULER 2.71

using namespace std;

int main() {
    // Using defined constants
    cout << "Value of PI: " << PI << endl;
    cout << "Value of EULER: " << EULER << endl;

    // Using macro functions
    int a = 5;
    cout << "Square of " << a << ": " << SQUARE(a) << endl;
    cout << "Cube of " << a << ": " << CUBE(a) << endl;

    // Conditional compilation
    #ifdef DEBUG
    cout << "Debug mode is ON" << endl;
    #endif

    // Inline code with preprocessor
    int b = 10;
    PRINT_VAR(b);

    // Stringizing operator
    cout << "Stringized version of PI: " << TO_STRING(PI) << endl;

    // Token pasting
    int MAKE_UNIQUE(my_var) = 20;
    cout << "Value of unique variable: " << MAKE_UNIQUE(my_var) << endl;

    // File inclusion
    string str = "Hello, World!";
    cout << "String value: " << str << endl;

    return 0;
}
