class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> inmst(n,false);
        vector<int> dist(n,INT_MAX);
        inmst[0] = true;
        int edgeCount = 0;

        for(int i=1; i<n; i++){
            dist[i] = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]);
        }
        int cost = 0;

        while(edgeCount < n-1){
            int currNode = -1;
            int minValue = INT_MAX;

            for(int i=0; i<n ; i++){
                if(!inmst[i] && dist[i] < minValue){
                    minValue = dist[i];
                    currNode = i;
                }
            }
            inmst[currNode] = true;
            cost += minValue;
            
            for(int i=0; i<n ; i++){
                if(!inmst[i]){
                    int newdist = abs(points[currNode][0] - points[i][0]) + abs(points[currNode][1] - points[i][1]);
                    dist[i] = min(dist[i], newdist);
                }
            }
            edgeCount++;
        }
        return cost;
    }
};
