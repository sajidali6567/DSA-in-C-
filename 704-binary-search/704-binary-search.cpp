class Solution {
public:
    int search(vector<int>& nums, int target) {
        return BS(nums, target, 0, nums.size()-1);
    }
    int BS(vector<int>& nums, int target, int start, int end) {
        if(start <= end) {
            int mid = (start+end)/2;
            if(nums[mid] == target) return mid;
            if(target > nums[mid]) {
                return BS(nums, target, mid+1, end);
            } else {
                return BS(nums, target, start, mid-1); 
            }
        }
        return -1;
    }
};