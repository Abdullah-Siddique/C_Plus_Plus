#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<vector<ll>>adj(n+1);
    ll u, v;
    while(cin>>u>>v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll>vis(n+1), res, level(n+1, -1);
    queue<ll>q;
    ll src = 1; 
    vis[src] = 1;
    level[src] = 1;
    q.push(src);
    while(!q.empty()){
        ll node = q.front();
        res.push_back(node);
        q.pop();
        for(auto ng: adj[node]){
            if(!vis[ng]){
                vis[ng] = 1;
                q.push(ng);
                level[ng] = level[node]+1;
            }
        }
    }
    cout<<"BFS: \n";
    for(auto e: res)cout<<e<<" ";
    cout<<"\n";
    for(ll i=0; i<=n; i++){
        cout<<"Level of node "<<i<<" is "<<level[i]<<" \n";
    }
    return 0;
    
}
