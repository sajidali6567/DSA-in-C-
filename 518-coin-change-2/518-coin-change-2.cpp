class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,0));
        
        for(int j=0;j<=amount;++j) {
            if(j % coins[0] == 0) dp[0][j] = 1;
            else dp[0][j] = 0;
        }
        for(int i=0;i<coins.size();++i) {
            dp[i][0] = 1;
        }        
        
        for(int index=1;index<coins.size();++index) {
            for(int target=1;target<=amount;++target) {
                int notTake = dp[index-1][target];
                int take = 0;
                if(coins[index] <= target) {
                    if(target-coins[index] >=0)
                        take = dp[index][target-coins[index]];
                } 
                dp[index][target] = take+notTake;
            }
        }
        return dp[coins.size()-1][amount];
    }
};