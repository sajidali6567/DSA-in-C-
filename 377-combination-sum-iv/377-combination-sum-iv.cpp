class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int target) {
        if(target == 0) return 1;
        int res = 0;
        if(dp[target] != -1) return dp[target];
        for(int i=0;i<nums.size();i++) {
            if(nums[i] <= target) {
                res += solve(nums, target-nums[i]);
            }
        }
        return dp[target] = res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1, -1);
        return solve(nums, target);
    }
};