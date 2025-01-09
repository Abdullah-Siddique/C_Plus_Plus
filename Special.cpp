/*
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⠏⢿⣿⣿⣿⣿⣯⠉⠉⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⠉⠉⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡍⠉⢹⣿⡍⠉⢹⣿⣿⣿⣿⣿⣿⣿⣿⣯⠉⠉⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⡏⠀⠈⢿⣿⣿⣿⣿⠀⠀⣿⠿⠿⣿⣿⣿⣿⡿⠿⢿⠀⠀⣿⣿⠿⠿⣿⡿⠿⠿⣿⣿⡇⠀⢸⣿⡇⠀⢸⣿⣿⣿⡿⠿⢿⣿⣿⣿⠀⠀⣿⡿⠿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡟⣼⣆⠀⠘⣿⣿⣿⣿⠀⠀⣴⣷⡄⠈⢿⣿⠃⢀⣾⣶⠀⠀⣿⣿⡆⠀⢸⣿⠄⠀⣿⣿⡇⠀⢸⣿⡇⠀⢸⣿⡏⠀⢻⣷⠀⢸⣿⣿⠀⠀⣵⣶⠀⠘⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⡟⣘⣛⣛⡂⠀⠘⣿⣿⣿⠀⠀⣿⣿⡇⠀⢸⡇⠀⢸⣿⣿⠀⠀⣿⣿⡇⠀⢸⣿⡀⠀⣿⣿⡇⠀⢸⣿⡇⠀⢸⣿⣿⠞⢋⣽⠀⢸⣿⣿⠀⠀⣿⣿⠀⠀⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡿⢱⣿⣿⣿⣿⡄⠀⠸⣿⣿⠀⡀⢿⣿⠃⢀⣿⣿⡀⠀⠿⠟⠀⠀⢿⣿⡇⠀⠸⡟⠁⠀⣿⣿⡇⠀⢸⣿⡇⠀⢸⣿⡁⠀⠻⣋⠀⠘⢿⣿⠀⠀⣿⣿⠀⠀⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣶⣶⣾⣿⣿⣿⣶⣶⣶⣾⣿⣶⣿⣶⣶⣾⣿⣿⣿⣿⣶⣶⣾⣶⣶⣿⣿⣿⣶⣶⣿⣷⣶⣾⣿⣶⣶⣶⣿⣶⣶⣶⣿⣿⣶⣾⣿⣶⣾⣿⣷⣶⣶⣾⣷⣶⣶⣾⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
*/

#include <bits/stdc++.h>
using namespace std;

// Shortcuts for common data types
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<vector<int>> vvi;

// Shortcuts for common operations 
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626

// Fast I/O
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

// Modulo operations
const int MOD = 1e9 + 7;
inline void addmod(int& a, int b) { a = (a + b) % MOD; }
inline void submod(int& a, int b) { a = (a - b + MOD) % MOD; }
inline void mulmod(int& a, int b) { a = (1LL * a * b) % MOD; }


void solve() {
    // You have to code here
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;  
    while(t--) {
        solve();
    }
    return 0;
}
