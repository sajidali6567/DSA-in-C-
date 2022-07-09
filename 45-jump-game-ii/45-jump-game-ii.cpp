class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 1e9);
        dp[nums.size()-1] = 0;
        for(int index = nums.size()-2;index>=0;index--) {
            int ans = 1e9;
            for(int i=1;i<=nums[index];i++) {
                if(index+i >= nums.size()) continue;
                ans = min(ans, 1+ dp[index+i]);
            }
            dp[index] = ans;
        }
        return dp[0]; 
    }
};