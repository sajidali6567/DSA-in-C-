class Solution {
public:
    void perm(vector<int>& ds, vector<int>& mp, vector<vector<int>>& ans, vector<int>& nums) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds); return;
        }
        for(int i=0;i<nums.size();++i) {
            // if not already present in ds
            if(!mp[i]) {
                mp[i] = 1;
                ds.push_back(nums[i]);
                perm(ds, mp, ans, nums);
                mp[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        vector<int> mp(n, 0);
        vector<vector<int>> ans;
        perm(ds, mp, ans, nums);
        return ans;
    }
};