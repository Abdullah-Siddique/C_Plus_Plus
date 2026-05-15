/*
g = gcd(a, b) = gcd(b, a % b)
ax + by = g = gcd(a, b)
a % b = a - (a/b) * b 
b * x1 + (a % b) * y1 = g // coefficients of (b, a % b)
b * x1 + (a - (a/b) * b) * y1 = g 
(b * x1) + (a * y1) - (a / b) * b * y1 = g 
b * (x1 - (a / b) *  y1) + (a * y1) = g 
(a * y1) + b * (x1 - (a / b) *  y1) = ax + by
So, x = y1, y = (x1 - (a / b) *  y1)

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
    ll x1, y1;
    ll gcd = eea(x1, y1, b, a % b);
    x = y1;
    y = (x1 - (a / b) *  y1);
    return gcd;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x, y, a, b;
    cin >> a >> b;
    cout << eea(x, y, a, b) << '\n';
    cout << "(x, y) = " << '(' << x << ", " << y << ')' << '\n';
    
    return 0;
}
