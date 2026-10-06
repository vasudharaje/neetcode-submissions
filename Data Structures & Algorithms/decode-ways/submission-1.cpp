class Solution {
private:
    vector<int> memo;

    int solve(const string& s, int i) {
        int n = s.length();

        // Base case: Reached the end of the string (1 valid decoding path found)
        if (i == n) return 1;

        // Leading '0' cannot be decoded
        if (s[i] == '0') return 0;

        // Return memoized result if already computed
        if (memo[i] != -1) return memo[i];

        // Choice 1: Take single digit s[i]
        int ways = solve(s, i + 1);

        // Choice 2: Take two digits s[i..i+1] if valid (10 to 26)
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