class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        minHeap.push({grid[0][0],0,0});
        visit[0][0] = true;

        while(!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();
            int t = curr[0]; int r = curr[1]; int c = curr[2];

            if(r == n-1 && c == n-1){
                return t;
            }
            for(const auto& dir: directions){
                int neir = r+ dir[0] ; int neic = c+ dir[1];
                if(neir < 0 || neic < 0 || neir == n || neic==n || visit[neir][neic]){
                    continue;
                }
                visit[neir][neic] = true;
                minHeap.push({max(t, grid[neir][neic]), neir,neic});
            }
        }
        return n*n;
    }
};
