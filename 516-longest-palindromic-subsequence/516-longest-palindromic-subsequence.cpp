class Solution {
public: 
    int longestPalindromeSubseq(string word1) {
        string word2(word1);
        reverse(word2.begin(), word2.end());
    
        // find the length of longest common subsequence in word1 and word2
        int M = word1.size(), N = word2.size();
        vector<int> prev(N+1, 0); vector<int> cur(N+1, 0);
        for(int i=1;i<=M;i++) {
            for(int j=1;j<=N;j++) {
                if(word1[i-1] == word2[j-1]) {
                    cur[j] = 1 + prev[j-1];
                } else {
                    cur[j] = max(prev[j], cur[j-1]);
                }
            }
            prev = cur;
        }
        return cur[N];
    }
};