class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<pair<int, int>> q;
        for(int i=0;i<nums.size();i++) {
            // maintain a monotonically decreasing queue
            while(!q.empty() && q.front().second <= i-k) {
                q.pop_front();
            }
            while(!q.empty() && q.back().first < nums[i]) {
                q.pop_back();
            }
            q.push_back({nums[i], i});
            if( i>= k-1) {
                res.push_back(q.front().first);
            }
        }
        return res;
    }
};