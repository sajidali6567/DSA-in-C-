class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(); int n = mat[0].size();
        
        vector<vector<int>> output(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, pair<int, int>>> q;
        
        for(int i=0;i<mat.size();++i) {
            for(int j=0;j<mat[0].size();j++) {
                if(mat[i][j]== 0) {
                    output[i][j] = 0;
                    q.push({i, {j, 0}});
                }   
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!q.empty()) {
            int cnt = q.size();
            while(cnt--) {
                int i = q.front().first;
                int j = q.front().second.first;
                int level = q.front().second.second; q.pop();
                for(int k=0;k<4;k++) {
                    int newI = i + dx[k];
                    int newJ = j + dy[k];
                    if(newI <0 || newJ <0 || newI >=m || newJ >= n || visited[newI][newJ]) continue;
                    q.push({newI, {newJ, level+1}});
                    output[newI][newJ] = min(output[newI][newJ], level+1);
                    visited[newI][newJ] = true;
                }
            } 
        }
        return output;
    }
};