/*
Problem Link: https://cses.fi/problemset/task/1668
Solution Author: Abdullah Siddique
Date: 2024-12-26

Solution:
    - This is a simple bfs problem.
    - We have to divide the pupils into two teams.
    - We will use a 2D vector to store the graph.
    - We will use a vector to store the teams of the pupils.
    - We will iterate through the graph and if the team of the pupil is not assigned then we will assign the team to the pupil.
    - We will use a queue to store the pupils.
    - We will iterate through the queue and check the pupils of the current pupil.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
int n, m;
cin>>n>>m;
vector<vector<int>>graph(n+1);
for(int i=0; i<m; i++){
    int a, b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
}
vector<int>teams(n+1, 0);

auto bfs = [&](int start) -> bool{
queue<int>q;
q.push(start);
teams[start] = 1;
 while(!q.empty()){
    int current = q.front();
    q.pop();

    for(int pupil: graph[current]){
        if(teams[pupil] == 0){
            teams[pupil] = 3 - teams[current];
            q.push(pupil);
        } else if(teams[pupil] == teams[current]){
               return false;
        }
    }
}
 return true;
};

for(int i=1; i<=n; i++){
    if(teams[i] == 0){
        if(!bfs(i)){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
}
for(int i=1; i<=n; i++){
    cout<<teams[i]<<" ";
}
cout<< endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
