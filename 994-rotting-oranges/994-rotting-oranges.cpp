class Solution {
public:
    bool isSafe(int row,int col, int m, int n) {
        return (row>=0 && row<m && col >=0 && col <n);
    } 
    
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int totalCnt = 0; // keep track of all oranges
        vector<int> rowBr = {1, -1, 0,  0};
        vector<int> colBr = {0,  0, 1, -1};
        queue<pair<int, int>>q;
        // find count of total oranges and push rotten oranges into queue
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j] == 1) {
                    totalCnt++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                    totalCnt++;
                }
            }
        }
        if(totalCnt == 0) return 0;
        // level will denote levels we need to travel in BFS
        int level = -1;
        int rottenOranges = 0; // keep track of rotten oranges till any minute
        while(!q.empty()) {
            rottenOranges += q.size();
            int cnt = q.size();
            while(cnt--) {
                int i = q.front().first;
                int j = q.front().second; q.pop();
                // traverse all the adjacent nodes
                for(int l=0;l<4;l++) {
                    int row = i+ rowBr[l];
                    int col = j+ colBr[l];
                    if( row < 0 || col <0 || row >= grid.size() || col >=grid[0].size() || grid[row][col] != 1) continue;
                    // push fresh oranges in queue as then have become rotten
                    q.push({row, col});
                    grid[row][col] = 2; // mark them as rotten
                    
                }
            }
            ++level;
        }
        return (rottenOranges==totalCnt)?level:-1;
    }
};