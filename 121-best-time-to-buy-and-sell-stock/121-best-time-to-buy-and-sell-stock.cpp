class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // index dp[n] max profit you can gain by buying the stock on day n
        int min = prices[0];
        int maxProf = 0;
        for(int i=1;i<prices.size();++i) {
            if(prices[i] < min) min = prices[i]; 
                int profit = prices[i]-min;
                maxProf = max(maxProf, profit);
        }
        return maxProf;
    }
};