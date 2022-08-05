class Solution {
public:
    set<vector<int>> combinations;
    void solve(vector<int>& candidates, int target, int index, vector<int>& combination) {
        if(target == 0) {
            combinations.insert(combination);
            return;
        }
        for(int i=index;i<candidates.size();i++) {
            if(i>index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] <= target) {
                combination.push_back(candidates[i]);
                solve(candidates, target-candidates[i], i+1, combination);
                combination.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        solve(candidates, target, 0, combination);
        vector<vector<int>> res(combinations.begin(), combinations.end());
        return res;   
    }
};