#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll b = 256;
const ll mod = 1e9 + 9;
bool issubstring(string &s, string &t){
    ll n = s.size(), m = t.size();
    if(m > n) return false;
    ll h = 1, hs = 0, ht = 0;
    for(ll i = 0; i < m - 1; i++) h = (h * b) % mod;
    
    for(ll i = 0; i < m; i++){
        hs = (hs * b + s[i]) % mod;
        ht = (ht * b + t[i]) % mod;
    }
    for(ll i = 0; i <= n - m; i++){
        if(hs == ht && s.substr(i, m) == t) return true;
        if(i < n - m){
            hs = (hs - ((s[i] * h) % mod) + mod) % mod;
            hs = (hs * b + s[i + m]) % mod;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    
    if(issubstring(s, t)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
