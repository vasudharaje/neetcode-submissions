class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        string t = "$#";
        for(char c: s){
            t += c;
            t += '#';
        }
        t += '^';
        int n = t.length();
        vector<int> P(n,0);
        int r = 0;
        int c = 0;

        for(int i=1; i< n-1 ; i++){
            int i_mirror = 2*c - i;
            if(i < r){
                P[i] = min(P[i_mirror], r-i);
            }
            while(t[i + P[i] + 1] == t[i - P[i] - 1]){
                P[i]++;
            }
            if( i + P[i] > r){
                c = i;
                r = i+P[i];
            }
        }
        int maxlen = 0, center = 0;
        for(int i=1; i<n-1 ; i++ ){
            if(P[i] > maxlen){
                maxlen = P[i];
                center = i;
            }
        }

        int start = (center - maxlen) / 2;
        return s.substr(start, maxlen);
    }
};
