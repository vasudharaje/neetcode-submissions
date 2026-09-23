class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(const auto& req : prerequisites){
            adj[req[1]].push_back(req[0]);
        }
        vector<int> state(numCourses,0);
        for(int i=0; i<numCourses; i++){
            if(state[i] == 0){
                if(hasCycle(i , adj, state)){
                    return false;
                }
            }
        }
        return true;
    }

private: 
    bool hasCycle(int u, vector<vector<int>>& adj, vector<int>& state){
        state[u] = 1;
        for(int v : adj[u]){
            if(state[v] == 1){
                return true;
            }
            if(state[v] == 0){
                if(hasCycle(v,adj,state)) 
                return true;
            }
        }
        state[u] = 2;
        return false;
    }
};
