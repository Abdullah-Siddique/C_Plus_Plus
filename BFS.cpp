
/*
Example input:
8 8 1 4
1 2
1 7
2 3
2 5
2 6
3 4
4 5
7 8

Output:

Adjacency List:

2 7
1 3 5 6
2 4
3 5
2 4
2
1 8
7
BFS array:
1 2 7 3 5 6 8 4
Path from 1 to 4 :
1 2 3 4
Distance of 0 from 1 is -1
Distance of 1 from 1 is 0
Distance of 2 from 1 is 1
Distance of 3 from 1 is 2
Distance of 4 from 1 is 3
Distance of 5 from 1 is 2
Distance of 6 from 1 is 2
Distance of 7 from 1 is 1
Distance of 8 from 1 is 2

Parent of node 0 is -1
Parent of node 1 is -1
Parent of node 2 is 1
Parent of node 3 is 2
Parent of node 4 is 3
Parent of node 5 is 2
Parent of node 6 is 2
Parent of node 7 is 1
Parent of node 8 is 7
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, e, src, dest;
    cin >> n >> e >> src >> dest;
    vector<vector<ll>> adj(n+1);
    for(ll i = 0; i < e; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "\nAdjacency List: \n";
    for(ll i = 0; i <= n; i++){
        for(auto e : adj[i]) cout << e << ' ';
        cout << '\n';
    }
    vector<bool> vis(n + 1, false);
    queue<ll> q;
    vector<ll> d(n + 1), p(n + 1), bfs;
    d[0] = p[0] = -1;
    vis[src] = true;
    q.push(src);
    p[src] = -1;
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto ng : adj[node]){
            if(!vis[ng]){
                vis[ng] = true;
                q.push(ng);
                d[ng] = d[node] + 1;
                p[ng] = node;
            }
        }
    }
    cout << "BFS array:\n";
    for(auto e : bfs) cout << e << ' ';
    cout << '\n';
    if(!vis[dest]) cout << "NO PATH\n";
    else{
        vector<ll> path;
        for(ll v = dest; v != -1; v = p[v]){
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        cout << "Path from " << src << " to " << dest << " : \n";
        for(ll v : path) cout << v << ' ';
        cout << '\n';
    }
    for(ll i = 0; i <= n; i++){
        cout << "Distance of " << i <<" from " << src << " is " << d[i];
        cout << '\n';
    }
    cout << '\n';

    for(ll i = 0; i <= n; i++){
        cout << "Parent of node " << i <<" is " << p[i];
        cout << '\n';
    }
    cout << '\n';

    return 0;
}
