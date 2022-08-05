class Solution {
public:
    set<vector<int>> combinations;
    void solve(vector<int>& candidates, int target, int index, vector<int>& combination, int k) {
        if(target == 0 && combination.size() == k) combinations.insert(combination);
        for(int i=index;i<candidates.size();i++) {
            if(i>index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] <= target) {
                combination.push_back(candidates[i]);
                solve(candidates, target-candidates[i], i+1, combination, k);
                combination.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates{1,2,3,4,5,6,7,8,9};
        vector<int> combination;
        solve(candidates, n, 0, combination, k);
        vector<vector<int>> res(combinations.begin(), combinations.end());
        return res; 
    }
};
