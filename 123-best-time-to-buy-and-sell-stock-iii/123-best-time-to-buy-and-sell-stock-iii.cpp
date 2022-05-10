class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>>front(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));
        // Base Cases are not required as we already intialized with zero
        for(int index = prices.size()-1;index>=0;index--) {
            for(int buy=1;buy>=0;buy--) {
                for(int k = 2;k>=1;k--) {
                    int profit = 0;
                    // Allowed to Buy Case
                    if(buy) {
                            profit = max(-prices[index] + front[0][k],  front[1][k]);
                    } else {
                        // sell case
                            profit = max(prices[index]+front[1][k-1],  front[0][k]);
                    }
                    cur[buy][k] = profit;
                }
            }
            front = cur;
        }
        
        return front[1][2];
    }
};