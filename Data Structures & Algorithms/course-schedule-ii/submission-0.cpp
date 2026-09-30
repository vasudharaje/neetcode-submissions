class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(const auto& req: prerequisites){
            int course = req[0];
            int prereq = req[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> order;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            order.push_back(curr);
            for(int neighb : adj[curr]){
                indegree[neighb]--;
                if(indegree[neighb]==0){
                    q.push(neighb);
                }
            }
        }
        if(order.size() == numCourses){
            return order;
        }
        return {};
    }

};
