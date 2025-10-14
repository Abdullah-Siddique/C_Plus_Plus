
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll bin1(vector<ll>&a ,ll x){
    ll n = a.size();
    ll l = 0, r = n-1;
    while(r-l >= 0){
        ll m = (r+l)/2;
        if(a[m] ==  x)return m;
        else if(a[m] < x){
            l = m+1;
        }
        else r = m-1;
    }
    return -1;
}

ll ub(vector<ll>&a ,ll x){
    ll n = a.size(), l = 0, r = n-1, ans = n;
    while(r-l >= 0){
        ll m = (r+l)/2;
        if(a[m] > x){
            ans = m;
            r = m-1;
        }
        else l = m+1;
    }
    return ans;
}

ll lb(vector<ll>&a ,ll x){
    ll n = a.size(), l = 0, r = n-1, ans = n;
    while(r-l >= 0){
        ll m = (r+l)/2;
        if(a[m] >= x){
            ans = m;
            r = m-1;
        }
        else l = m+1;
    }
    return ans;
}

double bin2(double x){
    double l = 1.0, h = x;
    if(x < 0) return -1;
    else if(x < 1){
        l = x, h = 1.0;
    }
    while(h-l>eps){
        double m = (h+l)/2.0;
        if(m*m == x) return m;
        else if(m*m > x){
            h = m;
        }
        else l = m;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> a = {1, 4, 5, 7, 9, 11, 12, 13};
    cout<<bin1(a, 9)<<"\n";
    cout<<ub(a, 13)<<"\n";
    cout<<lb(a, 13)<<"\n";
    cout<<bin2(25)<<"\n";
    return 0;
}
