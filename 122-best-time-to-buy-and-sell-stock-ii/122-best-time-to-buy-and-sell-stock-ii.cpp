class Solution {
public:
    int f(int index, int canBuy, vector<int>& prices, vector<vector<int>>& dp) {
        // Base Case
        if(index == prices.size()) {
            return 0;
        }
        if(dp[index][canBuy] != -1) return dp[index][canBuy];
        int profit = 0;
        if(canBuy) {
            // you can buy, so you have two option either buy or do not buy
            int buy = -prices[index] + f(index+1, 0, prices, dp);
            int notBuy = f(index+1, 1, prices, dp);
            profit = max(buy, notBuy);
        } else {
            // you can't buy, so try selling, you can choose to either sell or not
            int sell = prices[index] + f(index+1, 1, prices, dp);
            int notSell = f(index+1, 0, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[index][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // 1 represents you can buy, 0 represents you can not buy
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};