class Solution {
public:
    string longestPalindrome(string word1) {
        int n = word1.size();
        int start = 0, end =0;
        for(int i=0;i<n;i++) {
            int a = expandAround(word1, i, i);
            int b = expandAround(word1, i, i+1);
            int len = max(a, b);
            cout << len << " ";
            if(len > end-start) {
                start = i - (len-1)/2;
                end =  i + len/2;
            }
        }
        return word1.substr(start, end-start+1);
    }
    int expandAround(string word, int L, int R) {
        while(L>=0 && R < word.size() && word[L] == word[R]) {
            L--;R++;
        }
        return R-L-1;
    }
};