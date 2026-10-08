class Solution {
private: 
    // memo[i][j] = -1 (unvisited), 0 (false), 1 (true)
    vector<vector<int>> memo;

    bool dfs(string& s1, string& s2, string& s3, int i, int j) {
        if (i == s1.length() && j == s2.length()) {
            return true;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        bool take_from_s1 = false;
        bool take_from_s2 = false;
        if (i < s1.length() && s1[i] == s3[i + j]) {
            take_from_s1 = dfs(s1, s2, s3, i + 1, j);
        }
        if (j < s2.length() && s2[j] == s3[i + j]) {
            take_from_s2 = dfs(s1, s2, s3, i, j + 1);
        }
        return memo[i][j] = (take_from_s1 || take_from_s2);
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        memo.assign(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return dfs(s1, s2, s3, 0, 0);
    }
};