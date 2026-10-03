#include <vector>
#include <utility>

using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    // Constructor: parent gets size n, rank gets size n filled with 1s
    DSU(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Every node starts as its own parent
        }
    }

    // Find with iterative path compression
    int find(int node) {
        int cur = node;
        while (cur != parent[cur]) {
            parent[cur] = parent[parent[cur]]; 
            cur = parent[cur];
        }
        return cur;
    }

    // Union by size/rank
    bool unionSets(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) {
            return false; 
        }
        // Attach smaller tree under larger tree
        if (rank[pv] > rank[pu]) {
            swap(pu, pv);
        }

        parent[pv] = pu;
        rank[pu] += rank[pv];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int res = n;

        for (const auto& edge : edges) {
            if (dsu.unionSets(edge[0], edge[1])) {
                res--; 
            }
        }

        return res;
    }
};