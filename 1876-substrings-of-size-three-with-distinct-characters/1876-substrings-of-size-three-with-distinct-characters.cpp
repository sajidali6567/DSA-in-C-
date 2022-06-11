class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size()<3) return 0;
        int ans = 0;
        for(int i=0;i<s.size()-2;i++) {
            if(s[i] != s[i+1] && s[i+1] != s[i+2] && s[i+2] != s[i]) 
                ans++;
        }
        return ans;
    }
};