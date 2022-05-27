class Solution {
public:
    double myPow(double x, int n) {
        
        bool isNegative = (n < 0);
        // take long, as if n is INT_MIN, taking abs will out of int range
        long nn = abs(n);
        
        double ans = 1.0;

        while(nn > 0) { 
            if(nn % 2 == 0) {
                x = x * x;
                nn = nn/2;
            } else {
                ans = ans * x;
                nn = nn -1;
            }
        }
        return isNegative?1/ans:ans;
    }
};