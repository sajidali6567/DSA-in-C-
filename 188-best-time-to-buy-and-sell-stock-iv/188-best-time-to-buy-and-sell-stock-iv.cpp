class Solution {
public: 
    int maxProfit(int cap, vector<int>& prices) {
      vector<int> front(2*cap+1, 0), cur(2*cap+1, 0);
        for(int index = prices.size()-1;index>=0;index--) {
            for(int trans = 0;trans<2*cap;trans++) {
                int profit = 0;
        
                // Allowed to Buy Cas
                if(trans%2==0) {
                    profit = max(-prices[index] + front[trans+1],  front[trans]);
                } else {
                    // sell case
                    profit = max(prices[index]+ front[trans+1],  front[trans]);
                }
                cur[trans] = profit;
            }
            front = cur;
        }
        return front[0];
    }
};