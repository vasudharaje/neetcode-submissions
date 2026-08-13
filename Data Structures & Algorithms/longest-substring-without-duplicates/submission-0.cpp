class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> bag;
        int res = 0, curr = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (bag.count(s[i]) == 0) {
                bag[s[i]] = i;
                curr++;
                res = max(res, curr);
            }
            else {
                int old = bag[s[i]];
                for (int j = left; j <= old; j++) {
                    bag.erase(s[j]);
                }
                left = old + 1;
                bag[s[i]] = i;
                curr = i - left + 1;
                res = max(res, curr);
            }
        }
        return res;
    }
};