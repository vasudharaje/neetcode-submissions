class Solution {
public:
    int countSubstrings(string s) {
        string t = "$#";
        for(char c : s){
            t += c;
            t += "#";
        }
        t += "^";
        int n = t.size();
        int count = 0;
        for(int i=1; i< n-1 ; i++){
            int y = 0;
            int count_each=0;
            while(t[i+y] == t[i-y]){
                count_each++;
                y++;
            }
            count += count_each/2;
        }
        return count ;
    }
};
