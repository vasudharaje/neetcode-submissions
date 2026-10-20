class Solution {

    unordered_map<char, string> mapping = { {'2', "abc"}, {'3', "def"}, 
        {'4', "ghi"}, {'5', "jkl"},{'6', "mno"}, {'7', "pqrs"}, 
        {'8', "tuv"}, {'9', "wxyz"} };
    vector<string> res;

private:
    void dfs(int i, string curr, string& digits){
        if(i == digits.size()){
            res.push_back(curr);
            return;
        }
        string temp = mapping[digits[i]];
        for( char c : temp){
            curr.push_back(c);
            dfs(i+1, curr, digits);
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){return {};}
        string curr;
        dfs(0, curr, digits);
        return res;
    }
};
