
/*
My Graph:
A -> B, D
B -> A, D, C
C -> B, D, E
D -> A, B, C, E
E -> C, D

You may fall in confusion seeing add_edge function. 
This is called lambda function. A lambda function 
is a short, unnamed function that you can define 
inline in our code. Let's see its syntax:
[capture list] (parameters) -> return type { body of the function }

 In this code:
 auto add_edge = [&](int u, int v) { ... };
 `auto`: Automatically deduces the type of the lambda.
 `[&]`: The "capture list" specifies that the lambda 
        can access all variables by reference from the surrounding scope.
 `(int u, int v)`: The parameters of the lambda function.
 `{ body }`: The actual code that executes when the lambda is called.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 5; // Number of vertices
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0)); 

    auto add_edge = [&](int u, int v) {
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    };

    // Mapping 'A', 'B', 'C', 'D', 'E' to indices 0, 1, 2, 3, 4
    add_edge(0, 3); // A - D
    add_edge(0, 1); // A - B
    add_edge(1, 2); // B - C
    add_edge(1, 3); // B - D
    add_edge(2, 3); // C - D
    add_edge(2, 4); // C - E
    add_edge(3, 4); // D - E

    // Print the adjacency matrix
    cout << "Adjacency Matrix for the graph:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


