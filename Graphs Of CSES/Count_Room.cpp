/*
Problem Link: https://cses.fi/problemset/task/1192
Solution Author: Abdullah Siddique
Date: 2024-12-22

Solution:
    - This is a simple dfs problem.
    - We have to count the number of rooms in the grid.
    - We will use a 2D vector to store the grid.
    - We will use another 2D vector to store the visited nodes.
    - We will iterate through the grid and if we find a '.' and it is not visited then we will call the dfs function.
    - In the dfs function, we will mark the node as visited and then we will check the four directions of the node.
    - If the node is not visited and it is a '.' then we will call the dfs function again.
    - We will keep track of the number of times we call the dfs function and that will be our answer.
    - Finally, we will print the answer.
    - The time complexity of this solution is O(n*m) where n is the number of rows and m is the number of columns in the grid.
    - The space complexity of this solution is O(n*m) where n is the number of rows and m is the number of columns in the grid.
*/



#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited, int n, int m){
visited[x][y] = true;

for(int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == '.' && !visited[nx][ny]){
        dfs(nx, ny, grid, visited, n, m);
    }

}


}

int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);

int n,m;
cin>>n>>m;

vector<vector<char>> grid(n, vector<char>(m));

for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        cin>>grid[i][j];
    }
}
 vector<vector<bool>>visited(n, vector<bool>(m, false));

 int room = 0;


 for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        if(grid[i][j] == '.' && !visited[i][j]){
            room++;
            dfs(i, j, grid, visited, n, m);
        }
    }
}

cout<<room<<endl;

return 0;

}