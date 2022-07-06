class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;
        int prev1 = 0, prev2 = 1;
        int ans;
        for(int i=2;i<=n;i++) {
            ans = prev1 + prev2;
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
};