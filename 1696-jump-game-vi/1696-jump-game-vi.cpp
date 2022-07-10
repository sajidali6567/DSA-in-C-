class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), 0);   
        dp[0] = nums[0];
        deque<pair<int, int>> q;
        q.push_back({nums[0], 0});
        for(int i=1;i<nums.size();i++) {
            // pop from the front of the queue which are out of range
            while(!q.empty() && q.front().second < i-k) {
                q.pop_front();
            }
    
            dp[i] = nums[i] + q.front().first;
            // pop from back of the queue which is less than dp[i]
            while(!q.empty() && q.back().first <= dp[i]) {
                q.pop_back();
            }
            // push dp[i] window
            q.push_back({dp[i], i});
        }
        return dp[nums.size()-1];
    }
};