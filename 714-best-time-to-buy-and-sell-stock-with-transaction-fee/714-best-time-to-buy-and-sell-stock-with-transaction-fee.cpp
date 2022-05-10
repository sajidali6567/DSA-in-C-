class Solution {
public:
    int f(int index, int buy, vector<int>& prices, vector<vector<int>>& dp, int fee) {
        if(index >= prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        int profit = 0;
        if(buy) {
            profit = max(-prices[index] + f(index+1, 0, prices, dp, fee), f(index+1, 1, prices, dp, fee));
        } else {
            profit = max(prices[index] - fee + f(index+1, 1, prices, dp, fee), f(index+1, 0, prices, dp, fee));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
        return f(0,1, prices, dp, fee);
    }
};