class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <= 1) return 0;
        vector<int> dp(cost.size()+1, -1);
        return minCostClimbingStairsRec(cost, cost.size(), dp);
    }
    int minCostClimbingStairsRec(vector<int>& cost, int n,vector<int>& dp) {
        if(n <= 1) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = min(minCostClimbingStairsRec(cost, n-1, dp) + cost[n-1], minCostClimbingStairsRec(cost, n-2, dp)+cost[n-2]);
    }
};