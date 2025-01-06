/*
Problem Link: https://cses.fi/problemset/task/1669/
Solution Author: Abdullah Siddique
Date: 2025-01-06
Solution:
    - This is a simple dfs problem.
    - We have to find a cycle in the graph.
    - We will use a 2D vector to store the graph.
    - We will use a vector to store the parent of each node.
    - We will use a vector to store the visited status of each node.
    - We will start from each node and run a dfs.
    - If we find a node that is already visited then we have found a cycle.
    - We will store the start and end of the cycle.
    - Finally, we will print the cycle.
    - If we don't find any cycle then we will print "IMPOSSIBLE".
    - The time complexity of this solution is O(n+m) where n is the number of nodes and m is the number of edges in the graph.
    - The space complexity of this solution is O(n+m) where n is the number of nodes and m is the number of edges in the graph.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;
int start = -1, en = -1;

void dfs(int node, int par) {
    visited[node] = true;
    for (int neighbour : adj[node]) {
        if (neighbour == par) continue;
        if (visited[neighbour]) {
            start = neighbour;
            en = node;
            parent[neighbour] = node;
            return;
        }
        if (!visited[neighbour]) {
            parent[neighbour] = node;
            dfs(neighbour, node);
            if (start != -1) return;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
            if (start != -1) break;
        }
    }

    if (start == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> cycle;
    cycle.push_back(start);
    for (int v = en; v != start; v = parent[v]) {
        cycle.push_back(v);
    }
    cycle.push_back(start);


    cout << cycle.size() << "\n";
    for (int v : cycle) {
        cout << v << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}