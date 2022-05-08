class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int res = f(coins.size()-1, amount, coins, dp);
        return (res==1e9)?-1:res;
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