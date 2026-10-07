#include <string>
#include <vector>
#include <algorithm>

class Solution {
private:
    vector<vector<int>> memo;

    int dfs(const string& text1, const string& text2, int i, int j) {

        if (i == text1.length() || j == text2.length()) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (text1[i] == text2[j]) {
            return memo[i][j] = 1 + dfs(text1, text2, i + 1, j + 1);
        }

        return memo[i][j] = max(
            dfs(text1, text2, i + 1, j),  
            dfs(text1, text2, i, j + 1)  
        );
    }

public:
    int longestCommonSubsequence(string text1,string text2) {
        int m = text1.length();
        int n = text2.length();

        memo.assign(m, vector<int>(n, -1));

        return dfs(text1, text2, 0, 0);
    }
};