class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // index dp[n] max profit you can gain by buying the stock on day n
        if(prices.size() <=1) {
            return 0;
        }
        int min = prices[0];
        int ans = 0;
        int maxProf = INT_MIN;
        for(int i=1;i<prices.size();++i) {
            if(prices[i] < min) min = prices[i]; 
            int profit = prices[i] - min;
            if(profit < maxProf) {
                ans += maxProf;
                // cout << "ans = " << ans << endl;
                min = prices[i];
                maxProf = 0;
            } else {
                maxProf = max(profit, maxProf);
            }
            // cout << profit << " " << maxProf << endl;
        }
        ans += maxProf;
        return ans;
    }
};