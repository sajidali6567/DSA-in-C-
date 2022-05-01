// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // calculate indegree of all vertices
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++) {
            for(auto v:adj[i]) {
                indegree[v]++;
            }
        }
        // push all the vertices with indegree zero into queue
        queue<int> q;
        for(int i=0;i<indegree.size();++i) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
        
        int cnt = 0;
        // start BFS
        while(!q.empty()) {
            int temp = q.front();q.pop();cnt++;
            for(auto x:adj[temp]) {
                --indegree[x];
                if(indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        // if all vertices came into topo sort implies no cycle
        if(cnt == V) return false;
        return true;
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