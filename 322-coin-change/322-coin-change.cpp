class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        
        for(int j=0;j<=amount;++j) {
            if(j % coins[0] == 0) dp[0][j] = j/coins[0];
            else dp[0][j] = 1e9;
        }
        for(int i=1;i<coins.size();++i) {
            for(int j =0;j<= amount;++j) {
                int notTake = dp[i-1][j];
                int take = 1e9;
                if(coins[i] <=j) {
                    take = 1+dp[i][j-coins[i]];
                }
                dp[i][j] = min(take, notTake);
            }
        }
        return (dp[coins.size()-1][amount] == 1e9)?-1:dp[coins.size()-1][amount];
    }
    
    int f(int index, int target, vector<int>& coins, vector<vector<int>>& dp) {
        // Base Case
        if(index == 0) {
            if(target % coins[0] == 0) return target/coins[0];
            else return 1e9;
        }
        if(dp[index][target] != -1) return dp[index][target];
        int notTake = f(index-1, target, coins, dp);
        int take = INT_MAX;
        if(coins[index] <=target) {
            take = 1+f(index, target-coins[index], coins, dp);
        }
        return dp[index][target] = min(take, notTake);
    }
};