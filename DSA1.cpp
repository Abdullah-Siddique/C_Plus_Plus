#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return;
        if(rank[px] < rank[py]) parent[px] = py;
        else if(rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};


vector<vector<pair<int,int>>> adj;
vector<bool> visited;
vector<int> dist;

void dijkstra(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()) {
        int v = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if(d > dist[v]) continue;
        
        for(auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            
            if(dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                pq.push({dist[to], to});
            }
        }
    }
}


vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; i++) {
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if(i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}


int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b); 
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

vector<int> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for(int i = 2; i <= n; i++)
        if(is_prime[i]) primes.push_back(i);
    return primes;
}

int binary_search(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) return mid;
        if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}


int dp[1001][1001];
int solve(int i, int j) {
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = 0;
}

class SegTree {
    vector<int> tree;
    int n;
public:
    SegTree(int size) {
        n = size;
        tree.resize(4 * n);
    }
    
    void build(vector<int>& arr, int node, int start, int end) {
        if(start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2*node, start, mid);
        build(arr, 2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if(start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if(idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    int query(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return 0;
        if(l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2*node, start, mid, l, r) +
               query(2*node+1, mid+1, end, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 5;
    DSU dsu(n);
    dsu.unite(0, 1);
    dsu.unite(2, 3);
    cout << "Find(0): " << dsu.find(0) << endl;
    cout << "Find(2): " << dsu.find(2) << endl;
    
    int m = 5, start = 0;
    adj.resize(n);
    dist.assign(n, INT_MAX);
    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});
    adj[1].push_back({2, 5});
    adj[2].push_back({1, 5});
    adj[2].push_back({3, 1});
    adj[3].push_back({2, 1});
    adj[3].push_back({4, 2});
    adj[4].push_back({3, 2});
    dijkstra(start);
    cout << "Distance from node " << start << " to node 4: " << dist[4] << endl;

    string s = "abacaba";
    vector<int> z = z_function(s);
    cout << "Z-function for string: ";
    for(int i : z) cout << i << " ";
    cout << endl;
    
    int a = 24, b = 36;
    cout << "GCD of " << a << " and " << b << ": " << gcd(a, b) << endl;
    cout << "LCM of " << a << " and " << b << ": " << lcm(a, b) << endl;
    cout << "Is " << a << " prime? " << (isPrime(a) ? "Yes" : "No") << endl;

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    cout << "Binary search result for " << target << ": " << binary_search(arr, target) << endl;

    vector<int> seg_arr = {1, 2, 3, 4, 5};
    SegTree segTree(seg_arr.size());
    segTree.build(seg_arr, 1, 0, seg_arr.size() - 1);
    cout << "Query result for range (0, 3): " << segTree.query(1, 0, seg_arr.size() - 1, 0, 3) << endl;
    segTree.update(1, 0, seg_arr.size() - 1, 2, 10); // Update index 2 with value 10
    cout << "Query result after update for range (0, 3): " << segTree.query(1, 0, seg_arr.size() - 1, 0, 3) << endl;

    return 0;
}
