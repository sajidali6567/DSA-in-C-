class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = low +(high-low)/2;
            if( (mid==0 || nums[mid-1] < nums[mid]) and (mid == n-1 || nums[mid] > nums[mid+1]) ) {
                return mid;
            } else if(mid <n && nums[mid+1] > nums[mid]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return 0;
    }
};