#include <iostream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
    list<int> lst = {1, 2, 3, 4, 5};
    lst.push_back(6);
    lst.push_front(0);
    lst.pop_back();
    lst.pop_front();

    cout << "List elements: ";
    for (const auto& elem : lst) {
        cout << elem << " ";
    }
    cout << endl;

    deque<int> dq = {1, 2, 3, 4, 5};
    dq.push_back(6);
    dq.push_front(0);
    dq.pop_back();
    dq.pop_front();

    cout << "Deque elements: ";
    for (const auto& elem : dq) {
        cout << elem << " ";
    }
    cout << endl;

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Queue front: " << q.front() << endl;
    cout << "Queue back: " << q.back() << endl;
    q.pop();

    cout << "Queue elements after one pop: ";
    queue<int> tempQ = q;
    while (!tempQ.empty()) {
        cout << tempQ.front() << " ";
        tempQ.pop();
    }
    cout << endl;

    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    cout << "Stack top: " << stk.top() << endl;
    stk.pop();

    cout << "Stack elements after one pop: ";
    stack<int> tempS = stk;
    while (!tempS.empty()) {
        cout << tempS.top() << " ";
        tempS.pop();
    }
    cout << endl;

    set<int> st = {3, 1, 4, 1, 5, 9};
    st.insert(2);
    st.erase(1);

    cout << "Set elements: ";
    for (const auto& elem : st) {
        cout << elem << " ";
    }
    cout << endl;

    map<int, string> mp;
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    mp.insert({4, "four"});

    cout << "Map elements: ";
    for (const auto& pair : mp) {
        cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    cout << endl;

    unordered_set<int> uset = {5, 1, 2, 3, 2, 4};
    uset.insert(6);
    uset.erase(3);

    cout << "Unordered set elements: ";
    for (const auto& elem : uset) {
        cout << elem << " ";
    }
    cout << endl;

    unordered_map<string, int> umap;
    umap["one"] = 1;
    umap["two"] = 2;
    umap["three"] = 3;
    umap.insert({"four", 4});

    cout << "Unordered map elements: ";
    for (const auto& pair : umap) {
        cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    cout << endl;

    list<int> numbers = {1, 2, 3, 4, 5};
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Sum of list elements: " << sum << endl;

    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(1);

    numbers.sort();
    cout << "Sorted list elements: ";
    for (const auto& elem : numbers) {
        cout << elem << " ";
    }
    cout << endl;

    numbers.unique();
    cout << "Unique list elements: ";
    for (const auto& elem : numbers) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
