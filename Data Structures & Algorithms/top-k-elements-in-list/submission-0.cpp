class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int max_freq = 0; 
        
        for (int n : nums) {
            count[n]++;
            max_freq = max(max_freq, count[n]); 
        }
        
        vector<vector<int>> freq(max_freq + 1); 

        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i = max_freq; i > 0; --i) { 
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};