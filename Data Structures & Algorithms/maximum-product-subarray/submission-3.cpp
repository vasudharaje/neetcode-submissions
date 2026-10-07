class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int currMax = 1; int currMin = 1;
        for(int num : nums){
            int tmp = currMax*num;
            currMax = max(max(num*currMax, num*currMin) , num);
            currMin = min(min(tmp, num*currMin) , num);
            res = max(currMax, res);
        }
        return res;
    }
};
