class Solution {

private:
    vector<unordered_map<int,int>> memo;
    //memo can store no of ways to reach target from int i
    int count(vector<int>& nums, int target, int i,int current_sum){
        //for each i we have a decision to make 1. add 2.subtract 3.skip
        if(i==nums.size()){
            return current_sum == target ? 1:0;
        };
        if(memo[i].count(current_sum)) return memo[i][current_sum];

        int add = count(nums, target, i+1, current_sum + nums[i]);
        int subtract = count(nums, target, i+1 , current_sum - nums[i]);
        return memo[i][current_sum] = add + subtract;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        memo.resize(nums.size());
        return count(nums, target, 0, 0);
    }
};
