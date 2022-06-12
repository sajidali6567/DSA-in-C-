class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // find minimum length subarray whose sum is target
        int start = 0, sum = 0, ans = 1e9;
        for(int end=0;end<nums.size();end++) {
            sum += nums[end];
            
            while(sum >= target) {
                ans =min(ans, end-start+1);
                sum -= nums[start++];
            }
        }
        return ans==1e9?0:ans;
    }
};