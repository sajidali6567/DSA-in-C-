class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int start = 0, n=nums.size();
        long long sum = 0, ans = 0;
        for(int end=0;end<n;end++) {
            sum += nums[end];
            while(sum*(end-start+1) >= k) { // score = sum * length, note that start will never cross n
                sum -= nums[start++];
            }
            ans += (end-start+1);
        }
        return ans;
    }
};