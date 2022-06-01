class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7;
        int sumSofar = 0, oddCount = 0, evenCount = 0;
        for(auto x:arr) {
            sumSofar += x;
            (sumSofar&1)?oddCount++:evenCount++;
        }
        return oddCount%mod + ((long long)oddCount*evenCount)%mod;
    }
};

// [1,2,3,4,5,6,7]
// 1 3 6 10 15 21 28

// [1,3,5]
// 1 4 9