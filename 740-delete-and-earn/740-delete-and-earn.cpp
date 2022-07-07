class Solution {
public:
    map<int, int> mp;
    map<int, int> dp;
    int solve(int num) {
        if(num == 0 || num == 1) return mp[num];
        if(dp.find(num) != dp.end()) return dp[num];
        return dp[num] = max(solve(num-1), solve(num-2) + num*mp[num]);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxi = 0;
        for(auto num:nums) {
            maxi = max(maxi, num);
            mp[num]++;
        }
        return solve(maxi);
    }
};