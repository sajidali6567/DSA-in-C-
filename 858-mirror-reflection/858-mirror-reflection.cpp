class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm = p*q / gcd(p, q);
        int boxes = lcm / p;
        int reflection = lcm/q;
        if(reflection & 1) {
            if(boxes & 1) return 1;
            return 0;
        } 
        return 2;
    }
};