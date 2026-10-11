class Solution {

private:
    vector<vector<int>> memo;
    int dfs(string& word1, string& word2, int i, int j){
        int m = word1.size();
        int n = word2.size();
        if(i == word1.size()) return memo[i][j] = n-j;
        if(j == word2.size()) return memo[i][j] = m-i;
        if(memo[i][j]!= -1) return memo[i][j];
        if(word1[i] == word2[j]){
            return memo[i][j] = dfs(word1,word2, i+1,j+1);
        }
        else{
            int del = dfs(word1, word2, i+1, j);
            int insert = dfs(word1, word2, i, j+1);
            int replace = dfs(word1, word2, i+1, j+1);
            int temp = min(del, insert);
            return memo[i][j] = min(temp, replace) + 1;
        }
    }

public:
    int minDistance(string word1, string word2) {
        //add subtract remove , state variables -> i,j 
        // recursive rln min dfs(i,j) = min(dfs(add , j+1), dfs(subtract , j+1), dfs(replace, j+1))
        memo.assign(word1.size()+1, vector<int>(word2.size()+1, -1));
        return dfs(word1, word2, 0,0);
    }
};
