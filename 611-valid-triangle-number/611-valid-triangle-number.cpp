class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            int k = i+2;
            for(int j=i+1;j<nums.size();j++) {
                while(k < nums.size() && nums[k]<nums[i]+nums[j]) {
                    k++;
                }
                if(k-j-1 > 0) count += k-j-1;
            }
        }
        return count;
    }
};