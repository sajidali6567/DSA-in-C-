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
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return solve(nums, 0, -1, dp);
    }
};