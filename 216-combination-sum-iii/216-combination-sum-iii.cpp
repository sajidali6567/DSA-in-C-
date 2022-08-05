class Solution {
public:
    vector<vector<int>> combinations;
    void solve(int target, int index, vector<int>& combination, int k) {
        if(target == 0 && combination.size() == k) combinations.push_back(combination);
        for(int i=index;i<=9;i++) {
            if(i <= target) {
                combination.push_back(i);
                solve(target-i, i+1, combination, k);
                combination.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        solve(n, 1, combination, k);
        return combinations; 
    }
};
