class Solution {
public:
    // Brute Force, TC: 3*(n-3), n = s.size();
    bool isUniqueChar(string s, int start, int end) {
        map<char, int> mp;
        // check if substring of size 3 is having unique characters
        for(int j = start;j<=end;j++) {
            if(mp[s[j]]) {
                return false;
            }
            mp[s[j]]++;
        }
        return true;
    }
    int countGoodSubstrings(string s) {
        int count = 0;
        for(int i=2;i<s.size();i++) {
            count += isUniqueChar(s, i-3+1, i);
        }
        return count;
    }
};