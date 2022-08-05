class Solution {
public:
    vector<vector<int>> combinations;
    int n;
    
    void solve(vector<int>& candidates, int target, int index, vector<int>& combination) {
        if(target == 0) combinations.push_back(combination);
        for(int i=index;i<n;i++) {
            if(candidates[i] <= target) {
                combination.push_back(candidates[i]);
                solve(candidates, target-candidates[i], i, combination);
                combination.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> combination;
        solve(candidates, target, 0, combination);
        return combinations;
    }
};