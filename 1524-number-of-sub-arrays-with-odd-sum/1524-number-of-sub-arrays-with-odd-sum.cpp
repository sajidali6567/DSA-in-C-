class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long mod = 1e9+7;
        int sumSoFar = 0;
        int n = arr.size();
        int evenSumCount = 0, oddSumCount = 0;
        for(int i=0;i<n;i++) {
            sumSoFar += arr[i];
            if(sumSoFar % 2 == 0) {
                ++evenSumCount;
            } else {
                ++oddSumCount;
            }
        }
        return (oddSumCount%mod) + ( (long long) oddSumCount*evenSumCount)%mod;
    }
};