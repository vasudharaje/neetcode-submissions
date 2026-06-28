class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length()){
            return false;
        }
        unordered_map<char, int> scount;
        unordered_map<char, int> tcount;
        for(const char& n : s){
            scount[n]++;
        }
        for(const char& n : t){
            tcount[n]++;
        }
        return scount == tcount;
    }
};
