class Solution {
public:
    int trap(vector<int>& a) {
        int ans = 0, leftMax = 0, rightMax = 0;
        int l = 0, r = a.size()-1;
        while(l <= r) {
            if(a[l] <= a[r]) {
                if(a[l] < leftMax) {
                    ans += leftMax-a[l];
                } else {
                    leftMax = a[l];
                }
                l++;
            } else {
                if(a[r] < rightMax) {
                   ans += rightMax - a[r];
                } else {
                    rightMax = a[r];
                }
                r--;
            }
        }
        return ans;
    }
    
};