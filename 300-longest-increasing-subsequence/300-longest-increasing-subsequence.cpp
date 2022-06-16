class Solution {
public:
    // we need to keep prevIdx to check if next element can be included in our subsequence or not
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int idx = n-1;idx>=0;idx--) {
            for(int prevIdx=idx;prevIdx>=-1; prevIdx--) {
                int len = 0 + dp[idx+1][prevIdx+1];
                if(prevIdx == -1 || nums[idx] > nums[prevIdx]) {
                    len = max(len, 1 + dp[idx+1][idx+1]);
                }
                dp[idx][prevIdx+1] = len;
            }
        }
        return dp[0][-1+1];
    }
};