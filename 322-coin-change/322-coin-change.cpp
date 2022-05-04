class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -2));
    
        int res = helper(coins, coins.size()-1, amount, dp);
        if(res == 1e9) return -1;
        else return res;
    }
    // f(index, target) = minimum number of coins required to reach target using coins till index
    int helper(vector<int>& coins, int index, int target, vector<vector<int>>& dp) {
        if(index == 0) {
            if(target%coins[0] == 0) {
                return target/coins[0];
            } else {
                return 1e9;
            }
        }
        if(dp[index][target] != -2) {
            return dp[index][target];
        }
        int notTake = helper(coins, index-1, target, dp);
        int take = INT_MAX;
        if(coins[index] <= target) {
            take = 1+ helper(coins, index, target-coins[index], dp);
        } 
        return dp[index][target] = min(take, notTake);
    }
};