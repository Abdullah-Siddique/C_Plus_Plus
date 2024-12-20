/*
My Graph:
A -> B, D
B -> A, D, C
C -> B, D, E
D -> A, B, C, E
E -> C, D

Reference:
A -> 0, B -> 1, C -> 2, D -> 3, E -> 4

Here we have used the concept of "Array of 
vector". Let me clarify about it. Suppose,
you have an array of fixed size(e.g. here is mx).
Each element of the array is a distinct vector 
itself. We can dynamically change the size of
each vector as we need. Consider each element
of the array is a node. As we know that in
graph every node has its neighbour nodes. 
Those neighbour nodes are our vectors which
can be any size of.
*/

#include<bits/stdc++.h>
using namespace std;
const int mx = 5;
vector<int>adj_list[mx];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    adj_list[0] = {1, 3};
    adj_list[1] = {0 ,3, 2};
    adj_list[2] = {1, 3, 4};
    adj_list[3] = {0, 1, 2, 4};
    adj_list[4] = {2, 3};
    
    for(int i=0; i<mx; i++){
        cout<<char('A' + i)<<"->";
        for(int j: adj_list[i]){
            cout << char('A' + j) << " ";
        }
        cout << endl;
    }
    return 0;
}
