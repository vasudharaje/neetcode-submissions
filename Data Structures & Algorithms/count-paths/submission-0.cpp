#include <vector>

class Solution {
private:
    std::vector<std::vector<int>> memo;

    int dfs(int m, int n) {
        // Base case: A 1xN or Mx1 grid has only 1 straight path
        if (m == 1 || n == 1) return 1;

        // Return cached result
        if (memo[m][n] != -1) return memo[m][n];

        // Recurrence: Move Down (m - 1, n) + Move Right (m, n - 1)
        return memo[m][n] = dfs(m - 1, n) + dfs(m, n - 1);
    }

public:
    int uniquePaths(int m, int n) {
        // Initialize memo table of size (m+1) x (n+1) with -1
        memo.assign(m + 1, std::vector<int>(n + 1, -1));
        return dfs(m, n);
    }
};