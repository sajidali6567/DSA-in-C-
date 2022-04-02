
/* A Naive recursive implementation of
 0-1 Knapsack problem */
#include <bits/stdc++.h>
using namespace std;

#define NIL -1


int knapSackRec(int w, int* wt, int* val, int n) {
    if(n == 0 || w == 0) return 0;
    
    if(wt[n-1] > w) {
        return knapSackRec(w, wt, val, n-1);
    } else {
        return max(knapSackRec(w, wt, val, n-1), val[n-1] +knapSackRec(w-wt[n-1], wt, val, n-1));
    }
}

int knapSackMem(int w, int* wt, int* val, int n, vector<vector<int>> &dp) {
    if(dp[n][w] != NIL) return dp[n][w];

    if(wt[n-1] > w) {
        return dp[n][w] = knapSackRec(w, wt, val, n-1);
    } else {
        return dp[n][w] = max(knapSackRec(w, wt, val, n-1), val[n-1] +knapSackRec(w-wt[n-1], wt, val, n-1));
    }
} 

int knapSackDp(int W, int* wt, int* val, int N, vector<vector<int>> &dp) {
    for(int n = 1; n<=N; ++n) {
        for(int w =1; w<=W; ++w) {
            if(wt[n-1]>w) {
                dp[n][w] = dp[n-1][w];
            } else {
                dp[n][w] = max(dp[n-1][w], val[n-1] + dp[n-1][w-wt[n-1]]);
            }
        }
    }
    return dp[N][W];
}

// Driver code
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    // Creating a dp array of dimension n*W+1
    vector<vector<int>> dp( n + 1 , vector<int> (W+1, -1));
    dp[0][0] = 0;
    // cout << knapSackRec(W, wt, val, n);

    cout << knapSackMem(W, wt, val, n, dp);
    // cout << knapSackDp(W, wt, val, n, dp);
    return 0;
}
  