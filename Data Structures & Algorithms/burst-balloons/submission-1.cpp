class Solution {

private:
    vector<vector<int>> memo;
    int dfs(vector<int>& nums, int i, int j){
        if( j<= i+1){
            return 0;
        }
        if(memo[i][j] != -1) { return memo[i][j];}
        int max_coins = 0;
        for(int k = i+1 ; k<j ; k++){
            int coins = dfs(nums, i , k) + dfs(nums, k, j) + (nums[i] * nums[j] * nums[k]);
            max_coins = max(max_coins, coins);
        }
        return memo[i][j] = max_coins;
    }

public:
    int maxCoins(vector<int>& nums) {
        vector<int> newV; 
        newV.push_back(1);
        for(int num : nums){

            newV.push_back(num);
        }
        newV.push_back(1);
        int n = newV.size();
        memo.assign(n, vector<int>(n,-1));
        return dfs(newV, 0 , n-1);
    }
};
