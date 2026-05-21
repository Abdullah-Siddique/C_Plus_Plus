/*
nod -> number of divisors
sod -> sum of divisors
phi -> Euler's totient function
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 1e7 + 5;
ll spf[MAX];
void sieve(){
    for(ll i = 1; i <= MAX; i++){
        if(i & 1) spf[i] = i;
        else spf[i] = 2;
    }
    for(ll i = 3; i * i <= MAX; i += 2){
        if(spf[i] == i){
            for(ll j = 2 * i; j <= MAX; j += i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

ll nod(ll n){
    
    ll ans = 1;
    if(n % 2 == 0){
        ll cnt = 0;
        while(n % 2 == 0){
            cnt++;
            n /= 2;
        }
        ans *= (cnt + 1);
    }
    for(ll i = 3; i * i <= n; i += 2){
        if(n % i == 0){
            ll cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            ans *= (cnt + 1);
        }
    }
    if(n > 1) ans *= 2;
    return ans;
}

ll sod(ll n){
    if(n <= 0) return 0;
    ll ans = 1;
    while(n > 1){
        ll p = spf[n];
        ll a = p;
        while(n % p == 0){
            a *= p;
            n /= p;
        }
        ans *= (a - 1) / (p - 1);
    }
    return ans;
}

ll phi(ll n){
    if(n <= 0) return 0;
    ll res = n;
    while(n > 1){
        ll p = spf[n];
        res -= (res / p);
        while(n % p == 0){
            n /= p;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
	ll t;
	cin >> t;
	while(t--){
	    ll n;
	    cin >> n;
	    cout << "nod of n: " << nod(n) << '\n'; 
	    cout << "sod of n: " << sod(n) << '\n';
	    cout << "phi(n): " << phi(n) << '\n';
	}
	return 0;
}
