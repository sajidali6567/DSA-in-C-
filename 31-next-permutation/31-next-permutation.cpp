class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int n=nums.size();
        int k;
        // traverse from the back and find the first index where a[i] > a[i]+1
        for(k=n-2;k>=0;k--) {
            if(nums[k] < nums[k+1]) break;
        }
        // if no such point exist, it means it is the last permutation
        if(k<0) {
            reverse(nums.begin(), nums.end()); return;
        }
        // find the second index, from [last, index+1] which is greater than nums[index1]
        int l;
        for(l=n-1;l>k;l--) {
            if(nums[l] > nums[k]) {
                break;
            }
        }
        // if l does not exist then l will become equal to k
        swap(nums[k], nums[l]);
        // reverse the array starting from index k+1 to last
        reverse(nums.begin()+k+1, nums.end());
    }
};