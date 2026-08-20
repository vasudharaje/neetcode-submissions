class Solution {
public:
    bool isValid(string s) {
        stack<char> bigstack;
        
        for(char c: s) {
            if(c == '(' || c == '{' || c == '[') {
                bigstack.push(c);
            } 
            else {
        
                if(bigstack.empty()) {
                    return false;
                }
                
                if((c == ')' && bigstack.top() == '(') ||
                   (c == '}' && bigstack.top() == '{') ||
                   (c == ']' && bigstack.top() == '[')) {
                    bigstack.pop();
                } else {
                
                    return false;
                }
            }
        }
        return bigstack.empty();
    }
};