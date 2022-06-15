class Solution {
public:
    // f(idx, prev) = length of LIS starting from index idx whose previous element
    // is at prev index
    int solve(vector<int>& nums, int idx, int prevIdx, vector<vector<int>>& dp) {
        if(idx == nums.size()) {
            return 0;
        }
        if (dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];
        int notPick = 0 + solve(nums, idx+1, prevIdx, dp);
        int pick = -1;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]) {
            pick = 1 + solve(nums, idx+1, idx, dp);
        }
        return dp[idx][prevIdx+1] = max(pick, notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int idx=n-1;idx>=0;idx--) {
            for(int prevIdx=idx-1;prevIdx>=-1;prevIdx--) {
                int notPick = 0 + dp[idx+1][prevIdx+1];
                int pick = -1;
                if(prevIdx == -1 || nums[idx] > nums[prevIdx]) {
                    pick = 1 + dp[idx+1][idx+1];
                }
                dp[idx][prevIdx+1] = max(pick, notPick);
            }
        }
        return dp[0][-1+1];
    }
};