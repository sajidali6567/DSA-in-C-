class Solution {
public:
    int ans = 0;
    void merge(int arr[], int l, int mid, int r) {
         int leftArraySize = mid-l+1;
         int rightArraySize = r-mid;
         int leftArray[leftArraySize];
         int rightArray[rightArraySize];

         // copy left/right part of arr into temporary arrays
         for(int i=0;i<leftArraySize;i++) {
             leftArray[i] = arr[l+i];
         }
         for(int i=0;i<rightArraySize;i++) {
             rightArray[i] = arr[i+mid+1];
         }
         
         int i = 0, j = 0;
         while(i<leftArraySize && j < rightArraySize) {
             if((long long)leftArray[i] > 2 * (long long)rightArray[j]) {
                 ans += leftArraySize-i;
                 j++;
             } else {
                 i++;
             }  
         }    
        
         i=0, j =0; int k = l;
         // merge leftArraySize and rightArray into arr
         while(i<leftArraySize && j<rightArraySize) {
             if(leftArray[i] < rightArray[j]) {
                 arr[k] = leftArray[i];
                 i++;
             } else {
                 arr[k] = rightArray[j];
                 j++;
             }
             k++;
         }
         // check if some elements are left in leftArray
         while(i<leftArraySize) {
             arr[k] = leftArray[i];
             i++;k++;
         }
         // check if some elements are left in rightArray
         while(j<rightArraySize) {
             arr[k] = rightArray[j];
             j++;k++;
         }
    }
    void mergeSort(int arr[], int l, int r) {
        //code here
        if(l < r) {
            int mid = l + (r-l)/2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, r);
            merge(arr, l, mid, r);
        }
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int arr[n];
        for(int i=0;i<n;i++) {
            arr[i] = nums[i];
        }
        mergeSort(arr, 0, nums.size()-1);
        return ans;
    }
};