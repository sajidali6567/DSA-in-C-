class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> arr(nums.size()+1, false);
        for(auto x:nums) {
            if(arr[x])
                return x;
            arr[x] = true;
        }
        return 0;
    }
};