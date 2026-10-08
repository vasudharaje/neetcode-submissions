class Solution {

private:
    vector<vector<int>> memo;
    int dfs(int amount, vector<int>& coins, int i){
        if(amount==0) return 1;
        if(amount < 0) return 0;
        if(i >= coins.size()) return 0;

        if( memo[i][amount] != -1) return memo[i][amount];

        int take = dfs(amount-coins[i],coins, i);
        int skip = dfs(amount,coins, i+1);
        return memo[i][amount] = take + skip;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memo.assign(n, vector<int>(amount+1,-1));
        return dfs(amount, coins, 0);
    }
};
