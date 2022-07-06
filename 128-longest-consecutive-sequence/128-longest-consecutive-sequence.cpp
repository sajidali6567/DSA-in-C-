class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> mp(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++) {    
            // if nums[i]+1 is present in dictionary avoid it
            if(mp.find(nums[i]+1) != mp.end() )  {
                continue;
            }
            int count = 0;
            int num = nums[i];
            while(mp.find(num--) != mp.end()) {
                count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};