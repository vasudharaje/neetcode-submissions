class Solution {

private:
    vector<int> memo;
    bool dfs(vector<int>& nums, int i){
        if(i >= nums.size()-1){
            memo[i] = 1;
            return true;}
        if(nums[i] == 0){ 
            memo[i] = 0;
            return false;}
        if(memo[i] != -1) { return (memo[i]==1 ? true : false) ;}
        for(int j=1; j<= nums[i] ; j++){
            if(dfs(nums, i+j)){
            memo[i] = 1;
            return true;}
        }
        memo[i] = 0;
        return false;
    }

public:
    bool canJump(vector<int>& nums) {
        memo.assign(nums.size(), -1);
        return dfs(nums, 0);
    }
};
