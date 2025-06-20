#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool isPrime(ll n){
    if(n<2)return false;
    if(n==2 || n==3)return true;
    if(n%2==0 || n%3==0)return false;
    for(ll i =5; i*i<=n; i+=6){
        if(n%i==0 || n%(i+2)==0)return false;
    }
    return true;
}
bool isPerfect(ll n){
    if(n<2)return false;
    ll sum = 1;
    for(ll i=2; i*i<=n; i++){
        if(n%i==0)sum += i;
        if(i!=n/i)sum += n/i;
    }
    return sum==n;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    if(isPrime(n))cout<<"PRIME\n";
    else if(isPerfect(n))cout<<"PERFECT\n";
    else cout<<"NONE\n";
    return 0;
}
