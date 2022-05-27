class Solution {
public:
    int search(vector<int>& nums, int target) {
        return BS(nums, target, 0, nums.size()-1);
    }
    int BS(vector<int>& nums, int target, int start, int end) {
        if(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] == target) return mid;
            return target > nums[mid]? BS(nums, target, mid+1, end): BS(nums, target, start, mid-1); 

        }
        return -1;
    }
};