class Solution {
public:
    // check if three value form a triangle or not
    bool isValidTriangle(int a, int b, int c) {
        return (a+b>c)&&(a+c>b)&&(b+c>a);
    }
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                // search for all such c for which a + b > c
                auto it = upper_bound(nums.begin(), nums.end(), nums[i]+nums[j]-1);
                int temp = (it-nums.begin()-j-1);
                if(temp > 0) count += temp;
            }
        }
        return count;
    }
};