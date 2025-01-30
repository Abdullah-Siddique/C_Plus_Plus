#include <bits/stdc++.h>
using namespace std;

vector<int> suffix_array(string s) {
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n);
    vector<pair<char, int>> a(n);
    
    for (int i = 0; i < n; i++) {
        a[i] = make_pair(s[i], i);
    }
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) {
        p[i] = a[i].second;
    }
    
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first == a[i - 1].first) {
            c[p[i]] = c[p[i - 1]];
        } else {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }
    
    int k = 0;
    while (pow(2, k) < n) {
        vector<pair<pair<int, int>, int>> b(n);
        for (int i = 0; i < n; i++) {
            int second_rank_index = p[i] + pow(2, k);
            if (second_rank_index >= n) {
                second_rank_index = 0;
            }
            b[i] = make_pair(make_pair(c[p[i]], c[second_rank_index]), p[i]);
        }
        
        sort(b.begin(), b.end());
        
        for (int i = 0; i < n; i++) {
            p[i] = b[i].second;
        }
        
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (b[i].first == b[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        
        k = k + 1;
    }
    
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    vector<int> suffixArr = suffix_array(s);
    
    for (int i = 0; i < suffixArr.size(); i++) {
        cout << suffixArr[i] << " ";
    }
    
    return 0;
}
