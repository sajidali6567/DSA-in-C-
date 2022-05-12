// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        // create two temp arrays
        int leftArraySize = m-l+1;
        int rightArraySize = r-m;
        int* leftArray = new int[leftArraySize];
        int* rightArray = new int[rightArraySize];
        // copy the content into temp arrays
        for(int i=0;i<leftArraySize;i++) {
            leftArray[i] = arr[l+i];
        }
        for(int i=0;i<rightArraySize;i++) {
            rightArray[i] = arr[m+1+i];
        }
        // merge two temp array into original one
        int i=0,j=0,k=0;
        while(i<leftArraySize && j<rightArraySize) {
            if(leftArray[i] <= rightArray[j]) {
                arr[l+k] = leftArray[i];
                i++;
            } else {
                arr[l+k] = rightArray[j];
                j++;
            }
            k++;
        }
        while(i<leftArraySize) {
            arr[l+k] = leftArray[i];
            i++;
            k++;
        }
        while(j<rightArraySize) {
            arr[l+k] = rightArray[j];
            j++;
            k++;
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r) return;
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
        
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends