class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0, end = arr.size()-1;
        int ans = -1;
        while(start <= end) {
            int mid = (start+end)>>1;
            if(arr[mid]-mid-1 >= k) {
                end = mid-1;
            } else {
                ans = mid;
                start = mid +1;
            }
        }
        cout << ans << " ";
        return k + ans +1;
    }
};