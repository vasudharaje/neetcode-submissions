class Solution {

private: 
    vector<int> memo;
    int solve(vector<int>& nums, int i){
        int n = nums.size();
        if(i >= n) return 0;
        if(memo[i]!= -1) return memo[i];
        int mon1 = nums[i] + solve(nums, i+2);
        int mon2 = (i+1 < n) ? nums[i+1] + solve(nums, i+3) : 0;
        memo[i] = max(mon1,mon2);
        return memo[i];
    }

public:
    int rob(vector<int>& nums) {
        memo.assign(nums.size(),-1);
        if(nums.size() == 1) return nums[0];
        vector<int> nums1(nums.size()-1);
        vector<int> nums2(nums.size()-1);
        for(int i=0; i<nums.size()-1 ; i++){
            nums1[i] = nums[i];
        }
        for(int i=0; i<nums.size()-1 ; i++){
            nums2[i] = nums[i+1];
        }
        int opt1 = solve(nums1,0);

        memo.assign(nums2.size(), -1);
        int opt2 = solve(nums2,0);
        return max(opt1, opt2);
    }
};
