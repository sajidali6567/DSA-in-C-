class Solution {
public: 
    int maxProfit(int cap, vector<int>& prices) {
      vector<vector<int>> dp(prices.size()+1,vector<int>(2*cap+1, 0));
        for(int index = prices.size()-1;index>=0;index--) {
            for(int trans = 0;trans<2*cap;trans++) {
                int profit = 0;
        
                // Allowed to Buy Cas
                if(trans%2==0) {
                    profit = max(-prices[index] + dp[index+1][trans+1],  dp[index+1][trans]);
                } else {
                    // sell case
                    profit = max(prices[index]+ dp[index+1][trans+1],  dp[index+1][trans]);
                }
                dp[index][trans] = profit;
            }
        }
        return dp[0][0];
    }
};