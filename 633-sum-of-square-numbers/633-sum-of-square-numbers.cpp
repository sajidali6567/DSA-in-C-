class Solution {
public:
    bool judgeSquareSum(int c) {
        int sqrtc = sqrt(c);
        for(int i=0;i<=sqrtc;i++) {
            int bs = c - pow(i, 2);
            if(bs < 0) break;
            if(ceil(sqrt(bs)) == floor(sqrt(bs))) return true;
        }
        return false;
    }
};