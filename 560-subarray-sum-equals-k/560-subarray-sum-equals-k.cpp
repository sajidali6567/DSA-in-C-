class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sumSoFar = 0, count = 0;
        map<int, int> mp;
        for(auto num:nums) {
            sumSoFar += num;
            if(mp.find(sumSoFar-k) != mp.end()) count += mp[sumSoFar-k];
            if(sumSoFar == k) count++;
            mp[sumSoFar]++;
        }
        return count;
    }
};