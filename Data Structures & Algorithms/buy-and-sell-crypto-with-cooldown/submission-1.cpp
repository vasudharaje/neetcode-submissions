class Solution {

private: 
    vector<vector<int>> memo;
    int dfs(vector<int>& prices, bool buy, int i){
        if(i >= prices.size()){
            return 0;
        }
        if(memo[i][buy] != -1){
            return memo[i][buy];
        }
        if(buy){
            int buys = dfs(prices, false, i+1) - prices[i];
            int skips = dfs(prices, true, i+1);
            return memo[i][buy] = max(buys, skips);
        }
        int sell = dfs(prices, true, i+2) + prices[i];
        int skips = dfs(prices, false, i+1);
        return memo[i][buy] = max(sell, skips);

    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memo.assign(n, vector<int>(2,-1));
        return dfs(prices, true, 0);
    }
};
