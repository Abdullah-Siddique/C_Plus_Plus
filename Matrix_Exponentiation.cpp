#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
// Case for square matrix
vector<vector<ll>> mat_mul(vector<vector<ll>> &a, vector<vector<ll>> &b){
    ll n = a.size();
    vector<vector<ll>> c(n, vector<ll> (n, 0));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            for(ll k = 0; k < n; k++){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return c;
}
// Binary exponentiation
vector<vector<ll>> binexp(vector<vector<ll>> &a, ll p){
    ll n = a.size();
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for(ll i = 0; i < n; i++) res[i][i] = 1;
    while(p){
        if(p & 1) res = mat_mul(res, a);
        a = mat_mul(a, a);
        p >>= 1;
    }
    return res;
}

ll fib(ll n){
    if(n == 0) return 0;
    vector<vector<ll>> b = {{1, 1}, {1, 0}};
    vector<vector<ll>> res = binexp(b, n);
    return res[0][1];
}

void exe1(){
    ll n, p;
    cin >> n >> p;
    vector<vector<ll>> a(n, vector<ll> (n, 0));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> c = binexp(a, p);
    if(!c.empty()){
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                cout << c[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}

void exe2(){
    ll k;
    cin >> k;
    cout << "kth fibonacci number " << fib(k) << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    //cin.tie(0);
    cout << "Inputs for square matrix and its power:\n";
    exe1();
    cout << "Input for kth fibonacci number\n";
    exe2();
    return 0;
}
