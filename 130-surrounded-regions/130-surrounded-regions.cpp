class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        int m = board.size(); int n = board[0].size();
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        queue<pair<int, int>> q;
        // traverse boundary of grid and push 0 into queue
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i == 0 || i == m-1 || j == 0 || j == n-1) {
                    if(board[i][j] == 'O') {
                        q.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second; q.pop();
            for(int k=0;k<4;k++) {
                int row = i + dx[k];
                int col = j + dy[k];
                if(row <0 || row >=m || col <0 || col >= n || board[row][col] == 'X' || visited[row][col]) continue;
                q.push({row, col});
                visited[row][col] = true;
            }
        }
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};