
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll N = 2e6 + 5;
ll f[N], fi[N];

ll pw(ll x, ll n){
    x %= mod;
    ll ans = 1;
    while(n){
        if(n & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans;
}

ll minv(ll n){
    return pw(n, mod - 2);
}

void compute(){
    f[0] = fi[0] = 1;
    for(ll i = 1; i < N; i++) f[i] = (f[i - 1] * i) % mod;
    fi[N - 1] = minv(f[N - 1]);
    for(ll i = N - 2; i >= 1; i--){
        fi[i] = (fi[i + 1] * (i + 1)) % mod;
    }
}

ll ncr(ll n, ll r){
    if(r < 0 || r > n) return 0;
    ll ans = f[n];
    ans = (ans * fi[r]) % mod;
    ans = (ans * fi[n - r]) % mod;

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    compute();
    ll t;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        //calculating aCb
        ll a, b;
        cin >> a >> b;
        //cout << "Case " << i << " :";
        cout << ncr(a, b) << '\n';
    }

    return 0;
}
