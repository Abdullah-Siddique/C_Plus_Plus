/*
ax + mp = gcd(a, m) = 1
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll eea(ll &x, ll &y, ll a, ll b){
    if(b == 0){
        y = 0;
        x = 1;
        return a;
    }
    ll x1 = 0, y1 = 0;
    ll gcd = eea(x1, y1, b, a % b);
    x = y1;
    y = (x1 - (a / b) *  y1);
    return gcd;
}

ll modin(ll a, ll m, ll &x, ll &p){
    ll gcd = eea(x, p, a, m);
    if(gcd != 1) return -1;
    return (x % m + m) % m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, m, x, p;
    cin >> a >> m;
    cout << "MMI of a is : " << modin(a, m, x, p) << '\n';
    
    return 0;
}
