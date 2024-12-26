/*
Problem Link: https://cses.fi/problemset/task/1193
Solution Author: Abdullah Siddique
Date: 2024-12-23

Solution:
    - This is a simple bfs problem.
    - We have to find the shortest path from A to B in the grid.
    - We will use a 2D vector to store the grid.
    - We will use a queue to store the nodes.
    - We will use another 2D vector to store the visited nodes.
    - We will use another 2D vector to store the parent of the nodes.
    - We will use another 2D vector to store the direction of the nodes.
    - We will iterate through the grid and if we find 'A' then we will store the coordinates of that node.
    - We will iterate through the grid and if we find 'B' then we will store the coordinates of that node.
    - We will push the starting node in the queue and mark it as visited.
    - We will iterate through the queue and check the four directions of the node.
    - If the node is not visited and it is not a wall then we will push it in the queue and mark it as visited.
    - We will store the parent of the node and the direction of the node.
    - If we find the destination node then we will break the loop.
    - If we do not find the destination node then we will print "NO".
    - If we find the destination node then we will print "YES".
    - We will find the path from the destination node to the starting node.
    - Finally, we will print the path.
    - The time complexity of this solution is O(n*m) where n is the number of rows and m is the number of columns in the grid.
    - The space complexity of this solution is O(n*m) where n is the number of rows and m is the number of columns in the grid.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char moves[] = {'R', 'L', 'D', 'U'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    pair<int, int> st, en;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') st = {i, j};
            if (grid[i][j] == 'B') en = {i, j};
        }
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> direction(n, vector<char>(m, ' '));

    q.push(st);
    visited[st.first][st.second] = true;

    bool found = false;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                direction[nx][ny] = moves[i];
                q.push({nx, ny});

                if (grid[nx][ny] == 'B') {
                    found = true;
                    break;
                }
            }
        }
        if (found) break;
    }

    if (!visited[en.first][en.second]) {
        cout << "NO" << endl;
        return 0;
    }

    string path;
    pair<int, int> current = en;

    while (current != st) {
        char move = direction[current.first][current.second];
        path += move;
        current = parent[current.first][current.second];
    }
    reverse(path.begin(), path.end());

    cout << "YES" << endl;
    cout << path.length() << endl;
    cout << path << endl;

    return 0;
}
