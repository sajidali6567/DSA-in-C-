class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<arr.size();i++) {
            pq.push({arr[i], i});
        }

        vector<int> dp(arr.size(), 1);
        int ans = 1;
        while(!pq.empty()) {
            int cur = pq.top().first; int i = pq.top().second; pq.pop();
            int ans = 1;
            for(int x=1;x<=d;x++) {
                if(i+x >= n || arr[i+x] >= cur) {
                    break;
                }
                ans = max(ans, 1 + dp[i+x]);
            }
            for(int x=1;x<=d;x++) {
                if(i-x < 0 || arr[i-x] >= cur) {
                    break;
                }
                ans = max(ans, 1 + dp[i-x]);
            }
            dp[i] = ans;
        }
        return *max_element(dp.begin(), dp.end());
    }
};