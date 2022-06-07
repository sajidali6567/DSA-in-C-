class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = 0; 
        int ptr2 = 0;
        
        while(ptr1 < m + ptr2 && ptr2 < n) {
            if(nums1[ptr1] < nums2[ptr2]) {
                ptr1++;
            } else {
                // Insert nums2[ptr2] at ptr1th position in nums1
                nums1.insert(nums1.begin()+ptr1,nums2[ptr2]);
                ptr1++;ptr2++;
            }
        }
        while(ptr2 < n) {
            nums1[m + ptr2] = nums2[ptr2];
            ptr2++;
        }
        nums1.resize(m+n);
    }
};