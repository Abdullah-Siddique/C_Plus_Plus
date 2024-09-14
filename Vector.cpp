#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
    vector<int> vec1;
    vector<int> vec2(5, 10);
    vector<int> vec3 = {1, 2, 3, 4, 5};
    vector<int> vec4(vec3.begin(), vec3.end());

    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);

    cout << "Element at index 1: " << vec1[1] << endl;
    cout << "Element at index 1 (using at): " << vec1.at(1) << endl;
    cout << "First element: " << vec1.front() << endl;
    cout << "Last element: " << vec1.back() << endl;

    cout << "Iterating with index:" << endl;
    for (size_t i = 0; i < vec1.size(); ++i) {
        cout << vec1[i] << " ";
    }
    cout << endl;

    cout << "Iterating with iterator:" << endl;
    for (auto it = vec1.begin(); it != vec1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Iterating with range-based for loop:" << endl;
    for (int x : vec1) {
        cout << x << " ";
    }
    cout << endl;

    vec1.insert(vec1.begin() + 1, 100);
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());

    vec1.erase(vec1.begin() + 1);
    vec1.erase(vec1.begin(), vec1.begin() + 2);

    vec1.resize(10);
    vec1.reserve(20);
    cout << "Size: " << vec1.size() << ", Capacity: " << vec1.capacity() << endl;

    sort(vec1.begin(), vec1.end());
    reverse(vec1.begin(), vec1.end());
    int sum = accumulate(vec1.begin(), vec1.end(), 0);
    cout << "Sum of elements: " << sum << endl;

    auto it = find(vec1.begin(), vec1.end(), 10);
    if (it != vec1.end()) {
        cout << "Element 10 found at index: " << distance(vec1.begin(), it) << endl;
    } else {
        cout << "Element 10 not found" << endl;
    }

    vector<int> vec5;
    copy(vec1.begin(), vec1.end(), back_inserter(vec5));

    swap(vec1, vec5);

    vec1.clear();

    cout << "vec1: ";
    for (int x : vec1) {
        cout << x << " ";
    }
    cout << endl;

    cout << "vec5: ";
    for (int x : vec5) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
