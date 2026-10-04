class DSU {
public: 
    vector<int> parent;
    vector<int> size;
    DSU(int n): parent(n), size(n,1){
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int node){
        int curr = node;
        while(parent[curr] != curr){
            parent[curr] = parent[parent[curr]];
            curr = parent[curr];
        }
        return curr;
    }

    bool unionsets(int u, int v){
        int upu = find(u);
        int upv = find(v);
        if(upu == upv){
            return false;
        }
        if(size[upu]<size[upv]){
            swap(upu, upv);
        }
        parent[upv] = upu;
        size[upu] += size[upv];
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);
        for(const auto& edge: edges){
            if(!dsu.unionsets(edge[0], edge[1])){
                return {edge[0],edge[1]};
            }
        }
        return {};
    }
};
