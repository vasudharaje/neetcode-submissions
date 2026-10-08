class Solution {

private:
    vector<vector<int>> memo;
    vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int dfs(vector<vector<int>>& matrix,int r,int c){
        if(memo[r][c]!= -1) return memo[r][c];
        int max_path = 1;
        for(auto& [dr,dc] : directions){
            int newr = r + dr;
            int newc = c + dc;
            if(newr < matrix.size() && newr >=0 && newc < matrix[0].size() && newc >=0 && matrix[newr][newc] > matrix[r][c]){
                max_path = max(max_path,1+ dfs(matrix, newr, newc));
            }
        }
        return memo[r][c] = max_path;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        memo.assign(rows, vector<int>(cols, -1));
        int global_max = 0;
        for(int r=0; r<rows ; r++){
            for(int c=0; c<cols ;c++){
                global_max = max(global_max, dfs(matrix,r,c));
            }
        }
        return global_max;
    }
};
