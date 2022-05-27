class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        if(it == nums.end()) return {};
        
        vector<int> res;
        while(it != nums.end() && *it == target) {
            res.push_back(it-nums.begin());
            it++;
        }
        return res;
    }
};