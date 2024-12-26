/*
Problem Link: https://cses.fi/problemset/task/1666/
Solution Author: Abdullah Siddique
Date: 2024-12-23
Solution:
    - This is a simple dfs problem.
    - We have to find the number of connected components in the graph.
    - We will use a 2D vector to store the graph.
    - We will use a vector to store the visited nodes.
    - We will iterate through the graph and if we find a node that is not visited then we will call the dfs function.
    - In the dfs function, we will mark the node as visited and then we will check the neighbours of the node.
    - If the neighbour is not visited then we will call the dfs function again.
    - We will keep track of the number of times we call the dfs function and that will be our answer.
    - Finally, we will print the answer.
    - The time complexity of this solution is O(n*m) where n is the number of rows and m is the number of columns in the graph.
    - The space complexity of this solution is O(n*m) where n is the number of rows and m is the number of columns in the graph.
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &component) {
    visited[node] = true;
    component.pb(node);

    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, adj, visited, component);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<bool> visited(n + 1, false);
    vector<vector<int>> components;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, adj, visited, component);
            components.pb(component);
        }
    }

    int road = components.size() - 1;
    cout << road << endl;

    for (int i = 1; i < components.size(); i++) {
        cout << components[i - 1][0] << " " << components[i][0] << endl;
    }

    return 0;
}
