class Solution {
    vector<vector<int>> memo;
    vector<vector<string>> res;
private:

    bool isPal(string& s, int i, int j){
        if(i>=j){return true;}
        if(memo[i][j] != -1){ return memo[i][j];}
        if(s[i] == s[j]){
            return memo[i][j] = isPal(s, i+1, j-1);
        }
        return false;
    }

    void dfs(string& s, int start, vector<string>& curr){
        if(start == s.size()){ 
            res.push_back(curr);
            return;
        }
        for(int end = start; end< s.size() ; end++){
            if(isPal(s, start, end)){
                curr.push_back(s.substr(start, end-start+1));
                dfs(s,end+1,curr);
                curr.pop_back();
            }
        }
    }
    

public:
    vector<vector<string>> partition(string s) {
        memo.assign(s.size(), vector<int>(s.size(),-1));
        vector<string> curr;
        dfs(s,0,curr);
        return res;
    }
};
