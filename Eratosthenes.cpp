#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<bool>f(n+1, true);
    f[0] = f[1] = false; 
    for(ll i = 2; i <= n; i++){
        for(ll j = i*i; j <= n; j += i){
            f[j] = false;
        }
    }
    cout<<"Number of prime numbers: "<<count(f.begin(), f.end(), true)<<"\n";
    for(ll i=0; i<n+1; i++){
        if(f[i])cout<<i<<" ";
    }
}
