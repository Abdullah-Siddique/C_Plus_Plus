#include <bits/stdc++.h>
using namespace std;

class BIT {
    vector<int> tree;
    int n;
public:
    BIT(int size) {
        n = size;
        tree.resize(n + 1);
    }

    void update(int idx, int val) {
        while(idx <= n) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum += tree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word) {
            int idx = c - 'a';
            if(!curr->children[idx])
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word) {
            int idx = c - 'a';
            if(!curr->children[idx])
                return false;
            curr = curr->children[idx];
        }
        return curr->isEndOfWord;
    }
};

vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m);
    int len = 0;
    int i = 1;

    while(i < m) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) len = lps[len-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMP(string text, string pattern) {
    vector<int> lps = computeLPS(pattern);
    vector<int> result;
    int n = text.length();
    int m = pattern.length();
    int i = 0, j = 0;

    while(i < n) {
        if(pattern[j] == text[i]) {
            i++;
            j++;
        }
        if(j == m) {
            result.push_back(i-j);
            j = lps[j-1];
        }
        else if(i < n && pattern[j] != text[i]) {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return result;
}

void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(graph[i][k] != INT_MAX && graph[k][j] != INT_MAX &&
                   graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

vector<int> bellmanFord(vector<vector<int>>& edges, int V, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i = 1; i <= V-1; i++) {
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for(auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return vector<int>();
        }
    }

    return dist;
}

void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack, vector<vector<int>>& adj) {
    visited[v] = true;

    for(int u : adj[v]) {
        if(!visited[u])
            topologicalSortUtil(u, visited, Stack, adj);
    }

    Stack.push(v);
}

vector<int> topologicalSort(vector<vector<int>>& adj, int V) {
    stack<int> Stack;
    vector<bool> visited(V, false);

    for(int i = 0; i < V; i++)
        if(!visited[i])
            topologicalSortUtil(i, visited, Stack, adj);

    vector<int> result;
    while(!Stack.empty()) {
        result.push_back(Stack.top());
        Stack.pop();
    }
    return result;
}

int main() {
    cout << "Testing Binary Indexed Tree (BIT)" << endl;
    BIT bit(10);
    bit.update(1, 5);
    bit.update(2, 10);
    cout << "Sum of first 2 elements: " << bit.query(2) << endl;

    cout << "\nTesting Trie" << endl;
    Trie trie;
    trie.insert("apple");
    trie.insert("banana");
    cout << "Is 'apple' in Trie? " << trie.search("apple") << endl;
    cout << "Is 'orange' in Trie? " << trie.search("orange") << endl;

    cout << "\nTesting KMP Algorithm" << endl;
    string text = "ababcababcabcabc";
    string pattern = "abc";
    vector<int> result = KMP(text, pattern);
    cout << "Pattern 'abc' found at indices: ";
    for(int idx : result) cout << idx << " ";
    cout << endl;

    cout << "\nTesting Floyd-Warshall Algorithm" << endl;
    vector<vector<int>> graph = {
        {0, 5, INT_MAX, INT_MAX},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 2},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };
    floydWarshall(graph);
    cout << "Shortest paths after Floyd-Warshall:" << endl;
    for(auto& row : graph) {
        for(int cell : row) cout << (cell == INT_MAX ? "INF" : to_string(cell)) << " ";
        cout << endl;
    }

    // Testing Bellman-Ford
    cout << "\nTesting Bellman-Ford Algorithm" << endl;
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    vector<int> dist = bellmanFord(edges, 5, 0);
    if(!dist.empty()) {
        cout << "Shortest distances from source 0: ";
        for(int d : dist) cout << (d == INT_MAX ? "INF" : to_string(d)) << " ";
        cout << endl;
    }

    cout << "\nTesting Topological Sort" << endl;
    vector<vector<int>> adj = {
        {1, 2},
        {3},
        {3},
        {}
    };
    vector<int> topoSort = topologicalSort(adj, 4);
    cout << "Topological sort order: ";
    for(int v : topoSort) cout << v << " ";
    cout << endl;

    return 0;
}
