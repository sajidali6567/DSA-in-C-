class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> tempInt = intervals[0];
        for(auto it:intervals) {
            // Check if is overlapping, merge it
            if(it[0] <= tempInt[1]) {
                tempInt[1] = max(tempInt[1], it[1]);
            } else {
                res.push_back(tempInt);
                tempInt = it;
            }
        }
        res.push_back(tempInt);
        return res;
    }
};