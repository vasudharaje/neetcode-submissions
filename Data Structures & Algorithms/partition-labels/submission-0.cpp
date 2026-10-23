class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;
        for(int i=0; i< s.size() ; i++){
            last[s[i]] = i;
        }
        vector<int> result;
        int currMax = 0;
        int start = 0;
        for(int i=0; i < s.size() ; i++){
            currMax = max(currMax, last[s[i]]);
            if(i == currMax){
                int length = i - start + 1;
                result.push_back(length);
                start = i+1;
            }
        }
        return result;
    }
};
