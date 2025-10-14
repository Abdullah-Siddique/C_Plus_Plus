#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll &x: a)cin>>x;
    ll cs = a[0], mx = a[0];
    for(ll i=1; i<n; i++){
        cs = max(a[i], cs+a[i]);
        mx = max(cs, mx);
    }
    cout<<mx<<"\n";
}
