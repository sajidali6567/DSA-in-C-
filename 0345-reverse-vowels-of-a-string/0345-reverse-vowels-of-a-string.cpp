class Solution {
public:
    
    bool isVowel(char C) {
        return (C == 'a' || C == 'e' || C == 'i' || C == 'o' || C == 'u'
               || C == 'A' || C == 'E' || C == 'I' || C == 'O' || C == 'U');
    }
    
    string reverseVowels(string s) {
        int p1 = 0, p2 = s.size()-1;
        while(p1 <= p2) {
            
            if( isVowel(s[p1]) && isVowel(s[p2]) ) {
                swap(s[p1], s[p2]);
                p1++; p2--;
            } else {
                if(!isVowel(s[p1])) {
                    p1++;
                } else {
                    p2--;
                }
            }
        }
        return s;
    }
};