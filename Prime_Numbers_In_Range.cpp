
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll>soe(ll n){
    vector<bool>prime(n+1, true);
    vector<ll>ans;
    prime[0] = prime[1] = false;
    for(ll i=2; i*i<=n; i++){
        for(ll j=i*i; j<=n; j+=i){
            prime[j] = false;
        }
    }
    for(ll i=0; i<prime.size(); i++){
        if(prime[i])ans.push_back(i);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll m, n;
    cin>>m>>n;
    vector<ll>ans1, ans2, ans;
    
    ans1 = soe(m-1), ans2 = soe(n);
    for(auto e: ans2){
        if(e>=m){
            ans.push_back(e);
        }
    }
    for(auto e: ans)cout<<e<<" ";
    cout<<"\n";
 
    return 0;
}
