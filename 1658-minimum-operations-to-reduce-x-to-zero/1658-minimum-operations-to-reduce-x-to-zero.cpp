class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
            map<int,int> mp;
            mp[0] = -1;
            int n = nums.size();
            int total = 0;
            for(auto x : nums) {
                total += x;
            }
            int reqSum = total - x;
            if(reqSum == 0) {
                return n;
            }
            int prefSum = 0;
            int ans = -1;
            for(int i = 0; i < n; i++) {
                prefSum += nums[i];
                if (mp.find(prefSum - reqSum) != mp.end()) {
                    ans = max(ans, i - mp[prefSum - reqSum]);
                }
                mp[prefSum] = i;
            }
            if (ans == -1) {
                return -1;
            }
            return n - ans;
        }
};