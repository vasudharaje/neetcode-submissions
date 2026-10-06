class Solution {

private: 
    vector<int> memo;
    int solve(vector<int>& nums, int i){
        int n = nums.size();
        if(i>=n) return 0;
        if(memo[i] != -1) return memo[i];
        int mon1 = nums[i] + solve(nums,i+2);
        int mon2 = (i<=n-2) ? nums[i+1]+solve(nums, i+3) : 0;
        memo[i] = max(mon1,mon2);
        return memo[i];
    }

public:
    int rob(vector<int>& nums) {
        memo.assign(nums.size(), -1);
        return solve(nums, 0);
    }
};
