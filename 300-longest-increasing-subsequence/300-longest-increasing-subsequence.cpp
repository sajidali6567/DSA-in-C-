class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n+1, 1);
        int ans = 1;
        for(int i = 0;i<n;i++) {
            int maxi = 1;
            for(int prev = 0; prev<i;prev++) {
                if(nums[i] > nums[prev]) {
                    maxi = max(maxi, 1+lis[prev]);
                }
            }
            lis[i] = maxi;
            ans = max(ans, maxi);
        }
        return ans;
    }
};