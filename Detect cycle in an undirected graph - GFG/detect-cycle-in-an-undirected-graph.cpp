// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool isCyclicUtil(int node, vector<int> adj[], vector<bool>& visited) {
        queue<pair<int, int>> q;
        visited[node] = true;
        q.push({node, -1});
        while(!q.empty()) {
            int temp = q.front().first;
            for(auto v:adj[temp]) {
                if(!visited[v]) {
                    q.push({v, temp});
                    visited[v] = true;
                }
                else if (v != q.front().second) return true;
            }
            q.pop();
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                if(isCyclicUtil(i, adj, visited)) {
                    return true;
                }
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