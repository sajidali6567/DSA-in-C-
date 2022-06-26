class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for(int i=0;i<nums.size();i++) {
            int rightSum = totSum - leftSum - nums[i];
            if(leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};