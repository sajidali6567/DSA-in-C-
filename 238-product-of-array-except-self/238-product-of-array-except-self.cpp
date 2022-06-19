class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        int prod = 1;
        for(auto num:nums) {
            if(num == 0) zeroCount++;
            else prod = prod*num;
        }
        if(zeroCount > 1) {
            vector<int> res(nums.size(), 0);
            return res;
        }
        vector<int> res;
        for(auto num:nums) {
            if(zeroCount == 1) {
                if(num == 0) {
                    res.push_back(prod);
                } else {
                    res.push_back(0);
                }
            } else {
                res.push_back(prod/num);
            }
        }
        return res;
    }
};