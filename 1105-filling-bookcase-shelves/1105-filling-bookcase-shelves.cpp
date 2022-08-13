class Solution {
public:
    vector<int> dp;
    int solve(vector<vector<int>>& books, int shelfWidth, int index) {
        if(index == books.size()) {
            return 0;
        }
        if(dp[index] != -1) return dp[index];
        int curWidth = 0;
        int maxHeight = INT_MIN;
        int ans = INT_MAX;
        for(int i=index;i<books.size();i++) {
            curWidth += books[i][0];
            int height = books[i][1];
            if(curWidth <= shelfWidth) {
                maxHeight = max(maxHeight, height);
                ans = min(ans, maxHeight + solve(books, shelfWidth, i+1));
            }
        }
        return dp[index] = ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        dp.resize(books.size(), -1);
        return solve(books, shelfWidth, 0);
    }
};