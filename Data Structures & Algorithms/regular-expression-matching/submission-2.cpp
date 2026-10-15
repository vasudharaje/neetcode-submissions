class Solution {

private:
    vector<vector<int>> memo;
    bool dfs(string& s, string& p, int i, int j){
        if(j == p.size()) return i == s.size();
        if(memo[i][j] != -1) return memo[i][j];
        bool first_match = (i<s.size() && (s[i]==p[j] || p[j] == '.'));
        bool result = false;
        if(j+1 < p.size() && p[j+1] == '*'){
            result = dfs(s,p,i,j+2) || (first_match && dfs(s,p,i+1,j));
        }
        else{
            result = first_match && dfs(s,p,i+1,j+1);
        }
        return memo[i][j] = result;
    }

public:
    bool isMatch(string s, string p) {
        // state variable : index i in s and j in p
        // decisions -> include i or no, include as what, if j= *, s[i] can be anything, if . then j++ otherwise, s[i] must = p[j]
        // regression eqn : dfs(s,p,i,j) = dfs(s,p,i+1,j+1) || other cases formed
        //memo[i][j] can store true or false past i and j
        memo.assign(s.size()+1, vector<int>(p.size()+1,-1));
        return dfs(s,p,0,0);
    }
};
