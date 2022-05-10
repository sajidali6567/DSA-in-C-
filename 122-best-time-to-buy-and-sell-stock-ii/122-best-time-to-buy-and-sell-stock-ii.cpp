class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 1 represents you can buy, 0 represents you can not buy
        vector<int> front(2, 0);
        // Base Case
        front[0] = front[1] = 0;
        for(int index =prices.size()-1;index>=0;index--) {
             vector<int> cur(2, 0);
            for(int buy=1;buy>=0;--buy) {
                int profit = 0;
                if(buy) {
                    // you can buy, so you have two option either buy or do not buy
                    int buy = -prices[index] + front[0];
                    int notBuy = front[1];
                    profit = max(buy, notBuy);
                } else {
                    // you can't buy, so try selling, you can choose to either sell or not
                    int sell = prices[index] + front[1];
                    int notSell = front[0];
                    profit = max(sell, notSell);
                }
                cur[buy] = profit;
            }
            front = cur;
        }
        // because in recursion we called f(0, 1)
        return front[1];
    }
};