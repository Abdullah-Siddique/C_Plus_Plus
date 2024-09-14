#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

int main() {
    cout << "For Loop:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "i = " << i << endl;
    }

    cout << "\nWhile Loop:" << endl;
    int count = 0;
    while (count < 5) {
        cout << "count = " << count << endl;
        ++count;
    }

    cout << "\nDo-While Loop:" << endl;
    int num = 0;
    do {
        cout << "num = " << num << endl;
        ++num;
    } while (num < 5);

    cout << "\nRange-based For Loop (vector):" << endl;
    vector<int> vec = {1, 2, 3, 4, 5};
    for (int x : vec) {
        cout << "x = " << x << endl;
    }

    cout << "\nFor Loop with auto keyword (map):" << endl;
    map<int, string> mp = {{1, "one"}, {2, "two"}, {3, "three"}};
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        cout << "Key = " << it->first << ", Value = " << it->second << endl;
    }

    cout << "\nNested For Loop:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "(" << i << ", " << j << ") ";
        }
        cout << endl;
    }

    cout << "\nUsing Break in Loop:" << endl;
    for (int i = 0; i < 10; ++i) {
        if (i == 5) break;
        cout << "i = " << i << endl;
    }

    cout << "\nUsing Continue in Loop:" << endl;
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) continue;
        cout << "i = " << i << endl;
    }

    cout << "\nInfinite Loop (demonstration only, uncomment to use):" << endl;
     while (true) {
         cout << "This loop runs forever" << endl;
         break;
     }

    cout << "\nLoop with Iterator (vector):" << endl;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << "Value = " << *it << endl;
    }

    return 0;
}
