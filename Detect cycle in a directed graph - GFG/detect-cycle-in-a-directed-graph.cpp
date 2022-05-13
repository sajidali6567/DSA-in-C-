// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool isCyclicUtil(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& dfsVisited) {
        visited[node] = true; dfsVisited[node] = true;
        for(auto v:adj[node]) {
            if(!visited[v]) {
                if(isCyclicUtil(v, adj, visited, dfsVisited)) return true;
            } else if (dfsVisited[v]) {
                return true;
            }
        }
        dfsVisited[node] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> dfsVisited(V, false);
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                if( isCyclicUtil(i, adj, visited, dfsVisited) ) {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends