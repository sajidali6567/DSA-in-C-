// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool isCycleUtil(vector<int> adj[], int node,int parent, vector<bool>& visited) {
        visited[node] = true;
        for(auto u:adj[node]) {
            if(!visited[u]) {
                if(isCycleUtil(adj, u, node, visited)) return true;;
            } else if (parent!=u) {
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V+1, false);
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                if(isCycleUtil(adj, i, -1, visited)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends