// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
    // returns the index of node with minWeight
	int NodeWithMinWeight(vector<int>& nodeWt, vector<bool>& setMST) {
	    int min = INT_MAX;
	    int minIdx = -1;
	    for(int i=0;i<nodeWt.size();i++) {
	        if(!setMST[i] && nodeWt[i] < min) {
	            min = nodeWt[i];
	            minIdx = i;
	        }
	    }
	    return minIdx;
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Solve using Prim's Algorithm
        // u = i, v= adj[i][0], w= adj[i][1]
        // initialize nodeWeight array with all value as infinity
        vector<int> nodeWt(V, INT_MAX);
        
        // setMst is used to check whether node is included in MST or not
        vector<bool> setMst(V, false);
        // Make first node weight as zero so it gets picked first
        nodeWt[0] = 0;
        int ans = 0;
        for(int i=0;i<V;++i) {
            // pick the node with min node Weight
            int nodeWithMinWeight = NodeWithMinWeight(nodeWt, setMst);
            // include it in set MST
            setMst[nodeWithMinWeight] = true;
            // relax all adjacent nodes, which are not in SetMST
            for(int i=0;i<adj[nodeWithMinWeight].size();i++) {
                int v = adj[nodeWithMinWeight][i][0]; int w = adj[nodeWithMinWeight][i][1];
                if(w < nodeWt[v]) {
                    nodeWt[v] = w;
                }
            }
            // add included node weight in ans
            ans += nodeWt[nodeWithMinWeight];
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends