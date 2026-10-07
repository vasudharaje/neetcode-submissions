class Solution {

private: 
    vector<vector<int>> memo;
    bool dfs(vector<int>& nums, int i, int target){
        if(target == 0){
            return true;
        }
        if(target < 0 || i==nums.size()){
            return false;
        }
        if(memo[i][target]!= -1) return memo[i][target];
        memo[i][target] = dfs(nums,i+1,target) || dfs(nums, i+1, target-nums[i]);
        return memo[i][target];
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int num : nums){
            total += num;
        }
        if(total%2 == 1){ return false;}
        int target = total/2;
        memo.assign(n,vector<int>(target+1,-1));
        return dfs(nums,0, target);
    }
};
