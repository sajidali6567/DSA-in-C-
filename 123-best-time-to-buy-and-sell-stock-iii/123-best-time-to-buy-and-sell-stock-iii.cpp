class Solution {
public:
    int f(int index, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        // Base Case
        if(index == prices.size() || k == 0) {
            return 0;
        }
        if(dp[index][buy][k] != -1) return dp[index][buy][k];
        int profit = 0;
        // Allowed to Buy Cas
        if(buy) {
            profit = max(-prices[index] + f(index+1, 0, k, prices, dp),  f(index+1, 1, k, prices, dp));
        } else {
            // sell case
            profit = max(prices[index]+f(index+1, 1, k-1, prices, dp),  f(index+1, 0, k, prices, dp));
        }
        return dp[index][buy][k] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};