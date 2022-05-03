class Solution {
public:
    // basically you need to return fib(n)
    int climbStairs(int n) {
        if(n <= 2) {
            return n;
        }
        int prev1 = 1, prev2 = 2;
        for(int i=3;i<=n;i++) {
            int next = prev1 + prev2;
            prev1 = prev2;
            prev2 = next;
        }
        return prev2;
    }
};