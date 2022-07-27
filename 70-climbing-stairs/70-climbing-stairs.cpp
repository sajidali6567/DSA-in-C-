class Solution {
public:
    vector<int> dp;
    int solve(int index) {
        if(index < 0) return 0;
        if(index == 0) return 1;
        if(dp[index] != -1) return dp[index];
        return dp[index] = solve(index-1) + solve(index-2);
        
    }
    int climbStairs(int n) {
        dp.resize(n+1, -1);
        return solve(n);
    }
};