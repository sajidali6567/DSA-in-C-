class Solution {
public:
    int removePalindromeSub(string s) {
        string orig = s;
        reverse(s.begin(), s.end());
        if(orig == "") return 0;
        else if(s == orig) return 1;
        else return 2;
    }
};