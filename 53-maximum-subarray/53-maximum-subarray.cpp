class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumSoFar = 0, maxSum = INT_MIN;
        for(auto num:nums) {
            sumSoFar += num;
            maxSum = max(maxSum, sumSoFar);
            if(sumSoFar < 0) sumSoFar = 0;
        }
        return maxSum;
    }
};