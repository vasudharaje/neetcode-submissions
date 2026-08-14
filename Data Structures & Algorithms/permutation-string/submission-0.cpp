class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> freqs1(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            freqs1[s1[i] - 'a']++;
        }
        for (int i = 0; i <= s2.size() - s1.size(); i++) {
            
        
            vector<int> freqs2(26, 0); 
            
        
            for (int j = i; j < i + s1.size(); j++) {
                freqs2[s2[j] - 'a']++;
            }
            
            if (freqs1 == freqs2) {
                return true;
            }
        }
        return false;
    }
};