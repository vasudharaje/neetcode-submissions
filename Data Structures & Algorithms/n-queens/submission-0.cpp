class Solution {

private:
    vector<vector<string>> res;
    vector<bool> col, diag1, diag2;

    void dfs(int r, int n, vector<string>& curr){
        if(r == n){
            res.push_back(curr);
            return;
        }
        for(int c=0; c<n ; c++){
            int d1 = r+c;
            int d2 = r-c+n-1;
            if(col[c] || diag1[d1] || diag2[d2]){
                continue;
            }
            col[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            curr[r][c] = 'Q';
            dfs(r+1, n , curr);
            curr[r][c] = '.';
            diag1[d1] = false;
            diag2[d2] = false;
            col[c] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr(n , string(n , '.'));
        col.assign(n, false);
        diag1.assign(2*n, false);
        diag2.assign(2*n, false);
        dfs(0, n , curr);
        return res;
    }
};
