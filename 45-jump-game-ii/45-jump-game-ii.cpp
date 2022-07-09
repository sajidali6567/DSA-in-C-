class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int index) {
        if(index >= nums.size()) return 1e9;
        if(index == nums.size()-1) {
            return 0;
        }
        if(dp[index] != -1) return dp[index];
        int ans = 1e9;
        // try jumping 1 to nums[index]
        for(int i=1;i<=nums[index];i++) {
            ans = min(ans, 1+ solve(nums, index+i));
        }
        return dp[index] = ans;
    }

    int jump(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return solve(nums, 0); 
    }
};