
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1005, W = 1005;
ll dp[N][W];
/*
ll knapsack(vector<ll> &wt, vector<ll> &val, ll w, ll n){
    if(n == 0 || w == 0) return 0;
    if(wt[n - 1] <= w) return max(
        val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1),
        knapsack(wt, val, w, n - 1)
        );
    
    return knapsack(wt, val, w, n - 1);   
}
*/
// dp[i][j] = max profit for i elements and j capacity
// knapsack(wt[], val[], w, n) = max profit for n elements and w capacity
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, w;
    cin >> n >> w;
    vector<ll> wt(n), val(n);
    for(ll i = 0; i < n; i++) cin >> wt[i] >> val[i];
    
    for(ll i = 0; i <= n; i++) dp[i][0] = 0;
    for(ll j = 0; j <= w; j++) dp[0][j] = 0;
    
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= w; j++){
            if(wt[i - 1] <= j){
                ll yes = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                ll no = dp[i - 1][j];
                dp[i][j] = max(yes, no);
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][w] << '\n';

    return 0;
}
