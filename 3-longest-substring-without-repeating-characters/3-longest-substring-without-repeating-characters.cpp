class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int i=0, maxLength = 0, count =0;
        while(i<s.size()) {
            // When not found in map
            if(mp.find(s[i]) == mp.end()) {
                count++;
                mp[s[i]] = i;
                i++;
            } else {
                // s[i] is present in the map
                int index = mp[s[i]];
                // check if index is in range [i-count, i-1]
                if(index >= i-count && index <= i-1) {
                    maxLength = max(maxLength, count);
                    count = 0;
                    i = index + 1;
                    // remove that key from map
                    mp.erase(s[i]);
                } else {
                    // index is out of window range, ignore it
                    count++;
                    mp[s[i]] = i;
                    i++;
                }
            }
        }
        maxLength = max(maxLength, count);
        return maxLength;
    }
};