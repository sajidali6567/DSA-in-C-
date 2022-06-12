class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long prod = 1;
        int start = 0, ans =0, n = nums.size();
        for(int end=0;end<n;end++) {
            prod *= nums[end];
            while(start < n && prod >= k) {
                prod /= nums[start++];
            }
            ans += end-start+1;
        }
        return ans<0?0:ans;
    }
};