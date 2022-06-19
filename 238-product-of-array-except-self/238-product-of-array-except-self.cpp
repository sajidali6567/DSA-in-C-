class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pm(n+1, 1);
        vector<int> sm(n+1, 1);
        for(int i=1;i<=n;i++) {
            pm[i] = pm[i-1]*nums[i-1];
            sm[n-i] = sm[n-i+1] * nums[n-i];
        }

        vector<int> res(n, 0);
        for(int i=1;i<=n;i++) {
            res[i-1] = pm[i-1] * sm[i];
        }
        return res;
    }
};