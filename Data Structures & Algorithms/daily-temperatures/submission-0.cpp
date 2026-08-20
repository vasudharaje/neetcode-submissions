class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stack;
        vector<int> res(temperatures.size(),0);
        for(int i=0; i<temperatures.size(); i++){
            int t = temperatures[i];
            while(!stack.empty() && t > stack.top().first){
                res[stack.top().second] = i - stack.top().second;
                stack.pop();
            }
            stack.push({t,i});
        }
        return res;
    }
};
