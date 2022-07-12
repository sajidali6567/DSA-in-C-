class Solution {
public:
    vector<bool> visited;
    int ans = 0;
    void solve(int n, int index) {
        if(index == n+1) {
            ans++;
            return;
        }
        for(int i=1;i<=n;i++) {
            // Check i can be accomated at index 
            if(!visited[i] && (i%index == 0 || index %i==0) ) {
                visited[i] = true;
                solve(n, index+1);
                visited[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        visited.resize(n+1, false);
        solve(n, 1);
        return ans;
    }
};