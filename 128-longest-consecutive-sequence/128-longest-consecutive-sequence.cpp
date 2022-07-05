class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int ans = 1;
        for(int i=0;i<nums.size()-1;i++) {
            int count =1;
            while(i+1 < nums.size() ) {
                if (nums[i] +1 == nums[i+1]) {
                    i++; count++;
                } else if(nums[i] == nums[i+1]) {
                    i++;
                } else {
                    break;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};