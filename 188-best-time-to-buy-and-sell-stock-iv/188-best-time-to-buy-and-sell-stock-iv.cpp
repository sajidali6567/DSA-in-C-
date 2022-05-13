class Solution {
public:
    int maxProfit(int cap, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(cap+1, 0)));
        
        for(int index=prices.size()-1;index>=0;index--) {
            for(int buy=1;buy>=0;buy--) {
                for(int k=cap;k>=1;k--) {
                    int profit = 0;
                    if(buy) {
                        profit = max(-prices[index] + dp[index+1][0][k], dp[index+1][1][k]);
                    } else {
                        profit = max(prices[index] + dp[index+1][1][k-1], dp[index+1][0][k]);
                    }
                    dp[index][buy][k] =  profit;
                }
            }
        }
        
        return dp[0][1][cap];
    }
};