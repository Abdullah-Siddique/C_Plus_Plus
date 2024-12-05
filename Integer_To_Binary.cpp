#include <bits/stdc++.h>
using namespace std;

void convertToBinary(long long n) {
    if (n == 0) {
        cout << "0";
        return;
    }

    vector<int> binaryDigits;
    
    while (n > 0) {
        binaryDigits.push_back(n % 2);
        n /= 2;
    }

    for (int i = binaryDigits.size() - 1; i >= 0; i--) {
        cout << binaryDigits[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    if (number < 0) {
        cout << "-";
        number = -number;
    }

    cout << "Binary representation: ";
    convertToBinary(number);

    return 0;
}
