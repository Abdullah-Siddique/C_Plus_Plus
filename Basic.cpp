#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    for (int x : a) sum += x;
    cout << "Sum: " << sum << "\n";
    sort(a.begin(), a.end());
    cout << "Sorted: ";
    for (int x : a) cout << x << " ";
    cout << "\n";
    reverse(a.begin(), a.end());
    cout << "Reversed: ";
    for (int x : a) cout << x << " ";
    cout << "\n";
    cout << "Max: " << *max_element(a.begin(), a.end()) << "\n";
    cout << "Min: " << *min_element(a.begin(), a.end()) << "\n";
}

