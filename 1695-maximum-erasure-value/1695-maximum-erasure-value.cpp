class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        long sum = 0, ans = -1e9;
        int start = 0, n = nums.size();
        map<int,int> mp;
        for(int end =0;end<n;end++) {
            sum += nums[end];
            while(mp[nums[end]] != 0) {
                mp[nums[start]]--;
                sum -= nums[start++];
            }
            mp[nums[end]]++;
            ans = max(ans, sum);
        }
        return ans;
    }
};