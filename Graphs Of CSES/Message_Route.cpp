/*
Problem Link: https://cses.fi/problemset/task/1667/
Solution Author: Abdullah Siddique
Date: 2024-12-24
Solution:
    - This is a simple bfs problem.
    - We have to find the shortest path from node 1 to node n.
    - We will use a 2D vector to store the graph.
    - We will use a vector to store the distance of each node from node 1.
    - We will use a vector to store the parent of each node.
    - We will use a queue to store the nodes.
    - We will start from node 1 and push it into the queue.
    - We will mark the distance of node 1 as 0.
    - We will iterate through the queue until it is empty.
    - In each iteration, we will pop the front node from the queue.
    - We will iterate through the neighbours of the node.
    - If the neighbour is not visited then we will push it into the queue.
    - We will mark the distance of the neighbour as the distance of the current node + 1.
    - We will mark the parent of the neighbour as the current node.
    - Finally, we will print the distance of node n.
    - If the distance of node n is -1 then we will print "IMPOSSIBLE".
    - Otherwise, we will print the path from node 1 to node n.
    - The time complexity of this solution is O(n+m) where n is the number of nodes and m is the number of edges in the graph.
    - The space complexity of this solution is O(n+m) where n is the number of nodes and m is the number of edges in the graph.
*/
#include <bits/stdc++.h>
#define pb push_back
#define v vector
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    v<v<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    v<int> dist(n + 1, -1), parent(n + 1, -1);
    queue<int> q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbour : adj[node]) {
            if (dist[neighbour] == -1) {
                dist[neighbour] = dist[node] + 1;
                parent[neighbour] = node;
                q.push(neighbour);
            }
        }
    }

    if (dist[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        v<int> path;
        for (int current = n; current != -1; current = parent[current]) {
            path.pb(current);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;

        for (int i : path) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
