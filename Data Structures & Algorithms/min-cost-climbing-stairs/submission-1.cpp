class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> min_i(n,0);
        min_i[n-1] = cost[n-1];
        min_i[n-2] = cost[n-2];
        for(int i = n-3; i>=0 ; i--){
            min_i[i] = min(cost[i]+min_i[i+1], cost[i]+min_i[i+2]);
        }
        return min(min_i[0],min_i[1]);
    }
};
