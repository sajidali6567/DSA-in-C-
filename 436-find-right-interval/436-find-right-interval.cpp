class Solution {
public:
    #define pp pair<int,int>
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> arr;
        for(int i=0;i<intervals.size();i++) {
            // {start, index}
            arr.push_back({intervals[i][0], i});
        }
        // sort the arr vector
        sort(arr.begin(), arr.end());
        
        // traverse the array and find upper_bound for all the ends, if it exists push index in res or -1
        vector<int> res;
        for(int i=0;i<intervals.size();i++) {
            int end = intervals[i][1];
            auto it = lower_bound(arr.begin(), arr.end(), pp(end, INT_MIN));
            if(it == arr.end()) {
                res.push_back(-1);
            } else {
                res.push_back( arr[it-arr.begin()].second );
            }
        }
        return res;
    }
};