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

0 to 2 --->Traverse
2 to 0 --->Backtrack
0 to 1 --->Traverse
1 to 4 --->Traverse
4 to 5 --->Traverse
5 to 4 --->Backtrack
4 to 1 --->Backtrack
1 to 3 --->Traverse

*/

#include <bits/stdc++.h>
using namespace std;
void DFS(int start, vector<vector<int>>& adj_list){
    stack<int> Vnodes;
    vector<bool> visited(adj_list.size(), false);
    Vnodes.push(start);
    visited[start] = true;
    while(!Vnodes.empty()){
        int current = Vnodes.top();
        cout<<current<<" ";
        Vnodes.pop();
        for(int neighbour: adj_list[current]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                Vnodes.push(neighbour);
            }
        }
    }
}
int main() {
    
vector<vector<int>> graph = {
    {1, 2},    // Neighbors of vertex 0 -> graph[0]
    {0, 3, 4}, // Neighbors of vertex 1 -> graph[1]
    {0},       // Neighbors of vertex 2 -> graph[2]
    {1},       // Neighbors of vertex 3 -> graph[3]
    {1, 5},    // Neighbors of vertex 4 -> graph[4]
    {4}        // Neighbors of vertex 5 -> graph[5]
};

    
    cout << "DFS Traversal: "; // DFS Traversal: 0 2 1 4 5 3 
    DFS(0, graph);

    return 0;
} 

