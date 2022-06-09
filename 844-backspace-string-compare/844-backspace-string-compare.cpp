class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int p1 = s.size()-1;
        int p2 = t.size()-1;
        while(p1 >=0 || p2 >=0) {
            int count = 0;
            while( p1 >=0 && (s[p1] == '#' || count > 0) ) {
                if(p1 >=0 && s[p1] == '#') {
                    count++; p1--;
                } else {
                    count--;
                    p1--;
                }
            }
            
            count = 0;
            while(p2 >=0 && (t[p2] == '#' || count > 0) ) {
                if(p2 >=0 && t[p2] == '#') {
                    count++; p2--;
                } else {
                    count--; p2--;
                }
            }
            cout << p1 << " " << p2 << endl;
            if(p1 >=0 && p2 >=0 && s[p1] != t[p2]) return false;
            p1--;p2--;
        }
        if(p1 <0 && p2 < 0 && p1 == p2) return true;
        return false;
    }
};