#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll n = 1e5 + 5, inf = 1e9;
vector<ll> tree(4 * n, inf), a(n);

void build(ll node, ll start, ll end){
    if(start == end){
        tree[node] = a[start];
        return;
    }
    ll mid = (start + end) / 2;
    build(2 * node + 1, start, mid);
    build(2 * node + 2, mid + 1, end);
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}

ll query(ll node, ll start, ll end, ll i, ll j){
    if(i > end || j < start) return inf;
    if(i <= start && j >= end) return tree[node];
    ll mid = (start + end) / 2;
    ll left = query(2 * node + 1, start, mid, i, j);
    ll right = query(2 * node + 2, mid + 1, end, i, j);
    return min(left, right);
}

void update(ll node, ll start, ll end, ll idx, ll val){
    if(start == end){
        a[idx] = val;
        tree[node] = val;
    }
    else{
        ll mid = (start + end) / 2;
        if(start <= idx && mid >= idx){
            update(2 * node + 1, start, mid, idx, val);
        }
        else update(2 * node + 2, mid + 1, end, idx, val);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, Q;
    cin >> N >> Q;
    for(ll i = 0; i < N; i++) cin >> a[i];
    build(0, 0, N - 1);
    while(Q--){
        char q;
        cin >> q;
        ll r1, r2;
        cin >> r1 >> r2;
        if(q == 'q'){
            r1--; r2--;
            cout << query(0, 0, N - 1, r1, r2) << '\n';
        }
        else{
            r1--;
            update(0, 0, N - 1, r1, r2);
        }
    }

    return 0;
}
