class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0;
        target = accumulate(nums.begin(), nums.end(), target)-x;
        // find maximum length subarray whose sum is target
        int start = 0, sum = 0, ans = -1;
        for(int end=0;end<nums.size();end++) {
            sum += nums[end];
            while(start < nums.size() && sum > target) {
                sum -= nums[start++];
            }
            
            if(sum == target) 
                ans =max(ans, end-start+1);
        }
        return (ans==-1)?ans:nums.size()-ans;
    }
};