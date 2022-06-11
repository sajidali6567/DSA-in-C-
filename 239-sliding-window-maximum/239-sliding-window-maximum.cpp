class Solution {
public:
    #define pp pair<int, int>
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<pp> q;
        for(int i=0;i<nums.size();i++) {
            // if any values in front of array are out of window, pop them
            while(!q.empty() && q.front().second <= i-k) {
                q.pop_front();
            }
            // remove all the element whose valus are less than current value
            while(!q.empty() && q.back().first < nums[i]) {
                q.pop_back();
            }
            q.push_back({nums[i], i});
            // queue will always be sorted in decreasing order
            if(i>=k-1)
                res.push_back(q.front().first);
        }
        return res;
    }
};