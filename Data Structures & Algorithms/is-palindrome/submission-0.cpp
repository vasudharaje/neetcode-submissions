class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1; 
        
        while (i < j) {
            if (!alphanum(s[i])) {
                i++;
            }
            else if (!alphanum(s[j])) {
                j--;
            }
            else {
                if (tolower(s[i]) != tolower(s[j])) {
                    return false;
                }
                i++; 
                j--;
            }
        }
        return true;
    }

    bool alphanum(char c) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            return true;
        } else {
            return false; 
        }
    }
};