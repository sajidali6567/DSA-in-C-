class Solution {
public:
    int trap(vector<int>& height) {
        long ans = 0, n = height.size();
        vector<int> pre(n, INT_MIN);
        vector<int> suf(n, INT_MIN);
        pre[0] = height[0];
        suf[n-1] = height[n-1];
        for(int i=1;i<n;i++) {
            pre[i] = max(pre[i-1], height[i]);
            suf[n-1-i] = max(suf[n-i], height[n-1-i]);
        }
        for(int i=1;i<n;i++) {
            ans += min(pre[i], suf[i])- height[i];
        }
        return ans;
    }
    
};