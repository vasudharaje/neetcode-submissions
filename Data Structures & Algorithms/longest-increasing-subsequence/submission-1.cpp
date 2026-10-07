class Solution {

private: 
    vector<int> memo;
    int dfs(vector<int>& nums, int i ){
        if( memo[i] != -1) return memo[i];
        int max_len = 1;
        for(int j=i+1; j<nums.size() ; j++){
            if(nums[j]>nums[i]){
                max_len = max(max_len, 1+ dfs(nums, j));
            }
        }
        return memo[i] = max_len;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        memo.assign(nums.size(), -1);
        if(nums.empty()) return 0;
        for(int i=0;i<nums.size(); i++){
            dfs(nums,i);
        }
        return *max_element(memo.begin(),memo.end());
    }
};
