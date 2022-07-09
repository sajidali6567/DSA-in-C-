class Solution {
public:
    vector<bool> visited;
    bool solve(vector<int>& arr, int start) {
        visited[start] = true;
        if(arr[start] == 0) return true;
        // we have two options, either go left or go right
        bool left = false, right = false;
        if(start - arr[start] >=0 && !visited[start - arr[start]])
            left = canReach(arr, start - arr[start]);
        if(start + arr[start] < arr.size() && !visited[start + arr[start]])
            right = canReach(arr, start + arr[start]);
        return left || right;       
    }
    bool canReach(vector<int>& arr, int start) {
        visited.resize(arr.size(), false);
        return solve(arr, start);
    }
};