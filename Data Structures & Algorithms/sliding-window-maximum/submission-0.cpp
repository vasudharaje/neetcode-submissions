class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int r = 0, l = 0;
        deque<int> q;
        vector<int> output(n-k+1);

        while(r<n){
            while(!q.empty() && nums[q.back()] < nums[r]){
                q.pop_back();
            }
            q.push_back(r);
            if(l > q.front()){
                q.pop_front();
            }
            if((r+1) >= k){
                output[l] = nums[q.front()];
                l++;
            }
            r++;
        }
        return output;
    }
};
