class Solution {

private: 
    vector<int> memo;
    int dfs(vector<int>& coins, int remain){
        if(remain ==0) return 0;
        if(remain < 0) return -1;
        if(memo[remain] != -2){
            return memo[remain];
        }
        int min_coins = INT_MAX;
        for(int coin : coins){
            int res = dfs(coins, remain-coin);
            if(res != -1){
                min_coins = min(min_coins, res+1);
            }
        }
        memo[remain] = (min_coins == INT_MAX) ? -1 : min_coins;
        return memo[remain];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount+1, -2);
        return(dfs(coins,amount));
    }
};
