class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size(), medPos = (m + n+1)/2;
        int low = 0, high = m;
        double ans;
        while(low <= high) {
            int cut1 = low + (high-low)/2;
            int cut2 = medPos - cut1;
            int l1 = (cut1 == 0)?INT_MIN:nums1[cut1-1];
            int l2 = (cut2 == 0)?INT_MIN:nums2[cut2-1];
            int r1 = (cut1 == m)?INT_MAX:nums1[cut1];
            int r2 = (cut2 == n)?INT_MAX:nums2[cut2];
            if(l1 <= r2 && l2 <= r1) {
                double a = max(l1, l2);
                if( (m+n) & 1 ) {
                    return a;
                } else {
                    double b = min(r1, r2);
                    return (a+b)/2.0;
                }
            } else if (l1 > r2) {
                high = cut1-1;
            } else if(l2 > r1) {
                low = cut1+1;
            }
        }
        return ans;
    }
};