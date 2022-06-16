class Solution {
public:
    // we need to keep prevIdx to check if next element can be included in our subsequence or not
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1, 0); vector<int> cur(n+1, 0);
        for(int idx = n-1;idx>=0;idx--) {
            for(int prevIdx=idx;prevIdx>=-1; prevIdx--) {
                int len = 0 + next[prevIdx+1];
                if(prevIdx == -1 || nums[idx] > nums[prevIdx]) {
                    len = max(len, 1 + next[idx+1]);
                }
                cur[prevIdx+1] = len;
            }
            next = cur;
        }
        return cur[-1+1];
    }
};