#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void itob(ll n) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 2);
        n /= 2;
    }
    reverse(digits.begin(), digits.end());
    for (int d : digits) cout << d;
}

void btoi(ll n){
    ll ans = 0, i = 0;
    while(n > 0){
       ll digit = n % 10;
       if(digit == 1)ans += (1LL << i);
       n /= 10;
       i++;
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x, y; //We'll convert x to binary and y to decimal
    cin>>x;
    itob(x);
    cout<<"\n";
    cin>>y;
    btoi(y);
    cout<<"\n";
}
