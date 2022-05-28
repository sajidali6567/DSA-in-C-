class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] < nums[n-1]) return nums[0];
        int low = 0; int high = n-1;
        while(low <= high) {
            int mid = (low+high)/2;
            if(nums[0] <= nums[mid]) {
                low = mid +1;
            } else {
                high = mid-1;
            }
        }
        return nums[low];
    }
};