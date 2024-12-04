/*
Graph:
       0
      / \
     1   2
    / \
   3   4
        \
         5

Adjacency List:
0 -> 1 2
1 -> 0 3 4
2 -> 0
3 -> 1
4 -> 1 5
5 -> 4

0 to 1 --->Traverse     
0 to 2 --->Traverse
1 to 3 --->Traverse
1 to 4 --->Traverse
4 to 5 --->Traverse
5 to 4 --->Backtrack
4 to 1 --->Backtrack
3 to 1 --->Backtrack
2 to 0 --->Backtrack

       
/*
#include <bits/stdc++.h>
using namespace std;

void BFS(int start, vector<vector<int>>& adj_list) {
    queue<int> Qnodes;
    vector<bool> visited(adj_list.size(), false);

    Qnodes.push(start);
    visited[start] = true;

    while (!Qnodes.empty()) {
        int current = Qnodes.front();
        cout << current << " ";
        Qnodes.pop();

        for (int neighbour : adj_list[current]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                Qnodes.push(neighbour);
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},    // Neighbors of vertex 0
        {0, 3, 4}, // Neighbors of vertex 1
        {0},       // Neighbors of vertex 2
        {1},       // Neighbors of vertex 3
        {1, 5},    // Neighbors of vertex 4
        {4}        // Neighbors of vertex 5
    };

    cout << "BFS Traversal: "; // BFS Traversal: 0 1 2 3 4 5
    BFS(0, graph);

    return 0;
}
