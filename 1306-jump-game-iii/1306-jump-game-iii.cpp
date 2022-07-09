class Solution {
public:
    map<int, bool> mp;
    bool solve(vector<int>& arr, int start) {
        mp[start] = true;
        if(arr[start] == 0) return true;
        // we have two options, either go left or go right
        bool left = false, right = false;
        if(start - arr[start] >=0 && mp.find(start - arr[start]) == mp.end())
            left = canReach(arr, start - arr[start]);
        if(start + arr[start] < arr.size() && mp.find(start + arr[start]) == mp.end())
            right = canReach(arr, start + arr[start]);
        return left || right;       
    }
    bool canReach(vector<int>& arr, int start) {
        return solve(arr, start);
    }
};