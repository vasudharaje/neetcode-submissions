class Solution {

private:
    vector<int> memo;
    unordered_set<string> dict; 
    int maxLen = 0;
    bool dfs(string s, int i){
        if(i == s.length()) return true;
        if(memo[i] != -1) return memo[i];
        int lim = min(maxLen,(int)s.length()-i);
        for(int l=1; l<=lim ; l++){
            string prefix = s.substr(i,l);
            if(dict.count(prefix) && dfs(s, i+l)){
                return memo[i] = 1;
            }
        }
        return memo[i] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.assign(s.length(), -1);
        for(const auto& word : wordDict){
            dict.insert(word);
            maxLen = max(maxLen, (int)word.length());
        }
        return dfs(s, 0);
    }
};
