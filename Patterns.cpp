#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void p1(ll n){
    cout<<"P1: \n";
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void p2(ll n){
    cout<<"P2: \n";
    for(ll i=0; i<n; i++){
        for(ll j=0; j<=i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void p3(ll n){
    cout<<"P3: \n";
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=i; j++){
            cout<<j;
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void p4(ll n){
    cout<<"P4: \n";
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=i; j++){
            cout<<i;
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void p5(ll n){
    cout<<"P5: \n";
    for(ll i=0; i<n; i++){
        for(ll j=n-i; j>0; j--){
            cout<<"*";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void p6(ll n){
    cout<<"P6: \n";
    for(ll i=n; i>0; i--){
        for(ll j=1; j<=i; j++){
            cout<<j;
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void p7(ll n){
    cout<<"P7: \n";
        for(ll i=0; i<n; i++){
            for(ll j = n-i-1; j>0; j--)cout<<" ";
            for(ll j = 1; j<=2*i+1; j++)cout<<"*";
            for(ll j = n-i-1; j>0; j--)cout<<" ";
            cout<<"\n";
        } 
    cout<<"\n";    
}

void p8(ll n){
    cout<<"P8: \n";
        for(ll i=0; i<n; i++){
            for(ll j = 1; j<=i; j++)cout<<" ";
            for(ll j = 1; j<=2*(n-i)-1; j++)cout<<"*";
            for(ll j = 1; j<=i; j++)cout<<" ";
            cout<<"\n";
        }
    cout<<"\n";    
}

void p9(ll n){
    cout<<"P9: \n";
        for(ll i=0; i<n; i++){
            for(ll j = n-i-1; j>0; j--)cout<<" ";
            for(ll j = 1; j<=2*i+1; j++)cout<<"*";
            for(ll j = n-i-1; j>0; j--)cout<<" ";
            cout<<"\n";
        }
        for(ll i=0; i<n; i++){
            for(ll j = 1; j<=i; j++)cout<<" ";
            for(ll j = 1; j<=2*(n-i)-1; j++)cout<<"*";
            for(ll j = 1; j<=i; j++)cout<<" ";
            cout<<"\n";
        }  
    cout<<"\n";    
}

void p10(ll n){
    for(ll i = 1; i<=n; i++){
        for(ll j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    for(ll i = n-1; i>0; i--){
        for(ll j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    p1(n);
    p2(n);
    p3(n);
    p4(n);
    p5(n);
    p6(n);
    p7(n);
    p8(n);
    p9(n);
    p10(n);
    return 0;
}
