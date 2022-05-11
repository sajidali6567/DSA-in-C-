// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *nums, int n) {
        int xxory = 0;
        for(int i=0;i<n;i++) {
            xxory ^= nums[i];
        }
        for(auto i=1;i<=n;i++) {
            xxory ^= i;
        }
        // xxor is x^y which is xor of repeating and missing number
        int rightMostSetBit = xxory & ~(xxory-1);
        // divide elements into two set
        vector<int> set1, set2;
        for(int i=0;i<n;i++) {
            if(nums[i]&rightMostSetBit) {
                set1.push_back(nums[i]);
            } else {
                set2.push_back(nums[i]);
            }
        }
        for(auto i=1;i<=n;i++) {
            if(i&rightMostSetBit) {
                set1.push_back(i);
            } else {
                set2.push_back(i);
            }
        }
        // take xor of set1 and set2
        int res1 = 0;
        for(auto x:set1) {
            res1 ^= x;
        }
        int res2 = 0;
        for(auto x:set2) {
            res2 ^= x;
        }
        // assume res1 is missing number
        bool isRes1Missing = false;
        // Check which one is missing
        for(int i=0;i<n;i++) {
            if(nums[i] == res1) {
                isRes1Missing = true;
                break;
            }
        }
        int* z = new int[2];
        if(isRes1Missing) {
            z[0] = res1; z[1] = res2;
            return z;
        }
        z[0] = res2; z[1] = res1;
        return z;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends