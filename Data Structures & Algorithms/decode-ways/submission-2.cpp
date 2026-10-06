class Solution {
private:
    vector<int> memo;

    int solve(const string& s, int i) {
        int n = s.length();

        if (i == n) return 1;

        if (s[i] == '0') return 0;

        if (memo[i] != -1) return memo[i];

        int ways = solve(s, i + 1);

        if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            ways += solve(s, i + 2);
        }
        
        return memo[i] = ways;
    }

public:
    int numDecodings(string s) {
        memo.assign(s.length(), -1);
        return solve(s, 0);
    }
};