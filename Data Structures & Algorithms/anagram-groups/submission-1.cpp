class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> bag;
        for(const string& str: strs){
            vector<int> count(26,0);
            for(char c : str){
                count[c - 'a']++;
            }
            string key;
            for(int i : count){
                key += to_string(i) + ',';
            } 
            bag[key].push_back(str);
        }
        vector<vector<string>> res;
        for(const auto& vect: bag){
            res.push_back(vect.second);
        }
        return res;
    }
};
