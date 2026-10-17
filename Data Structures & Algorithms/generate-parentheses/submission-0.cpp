class Solution {

private:
    vector<string> res;
    void dfs(int n, int open, int close,string& curr){
        if(open == close && open == n){
            res.push_back(curr);
            return;
        }
        if(open < n){
            curr += '(';
            dfs(n, open+1, close, curr);
            curr.pop_back();
        }
        if(close<open){
            curr += ')';
            dfs(n, open, close+1, curr);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string curr;
        dfs(n,0,0,curr);
        return res;
    }
};
