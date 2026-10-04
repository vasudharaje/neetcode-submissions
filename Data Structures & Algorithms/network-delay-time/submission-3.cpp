class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(const auto& time: times){
            int u = time[0];
            int v = time[1];
            int t = time[2];
            adj[u].push_back({v,t});
        }
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> minheap;
        dist[k] = 0;
        minheap.push({0,k});

        //loop starts
        while(!minheap.empty()){
            auto [time,u] = minheap.top();
            minheap.pop();
            if(time>dist[u]) continue;
            for(const auto& [v,weight] : adj[u]){
                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u]+weight;
                    minheap.push({dist[v],v});
                }
            }
        }
        int maxtime = 0;
        for(int i=1; i<=n ; i++){
            if(dist[i] == INT_MAX) return -1;
            maxtime = max(maxtime,dist[i]);
        }
        return maxtime;
    }
};
