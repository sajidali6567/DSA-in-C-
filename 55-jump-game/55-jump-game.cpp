class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int index) {
        if(index >= nums.size()) return false;
        if(index == nums.size()-1) return true;
        if(dp[index] != -1) return dp[index];
        // try jumping 1 to nums[index]
        for(int i=1;i<=nums[index];i++) {
            if(solve(nums, index+i))
                return dp[index] = true;
        }
        return dp[index] = false;
    }
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return solve(nums, 0);
    }
};