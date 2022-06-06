class Solution {
public:
    // we will use prefix function to solve this problem
    int strStr(string haystack, string needle) {
        int n = needle.size();
        if(needle.size() == 0) return 0;
        int m = haystack.size();
        string s = needle + '#' + haystack;
        // calculate prefix function pi for the above string
        int pi[m+n+1];
        pi[0] = 0;
        for(int i=1;i<m+n+1;++i) {
            int j = pi[i-1];
            while(j > 0 && s[i] != s[j])
                j = pi[j-1];

            if(s[i] == s[j])
                j++;
            pi[i] = j;
            
            if(pi[i] == n) {
                return (i - 2*n);
            }
        }
        return -1;
    }
};