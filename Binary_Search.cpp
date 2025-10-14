
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double eps = 1e-7;

double multiply(double x, double n){
    double ans = 1.0;
    for(ll i=0; i<n; i++)ans*=x;
    return ans;
}

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

double bin2(double x, double n){
    double l = 1.0, h = x;
    if(x < 0) return -1;
    else if(x < 1){
        l = x, h = 1.0;
    }
    while(h-l>eps){
        double m = (h+l)/2.0;
        if(multiply(m, n) == x) return m;
        else if(multiply(m, n) > x){
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
    cout<<fixed<<setprecision(6)<<bin2(27, 4)<<"\n";
    return 0;
}
