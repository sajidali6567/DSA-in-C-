class Solution {
public:
    void prepAdj(vector<vector<int> > &adj, vector<vector<int> > &B) {
        for(int i=0;i<B.size();++i) {
            adj[B[i][0]].push_back(B[i][1]);
        }
    }

    int isCyclic(vector<vector<int> > &adj, vector<int>& visited,             vector<int>& bfsVisited, int node) {
        bfsVisited[node] = true; visited[node] = true;
        for(auto v:adj[node]) {
            if(!visited[v]) {
                if(isCyclic(adj, visited, bfsVisited, v))
                    return 1;
            } else if (bfsVisited[v] == 1) {
                return 1;
            }
        }
        bfsVisited[node] = false;
        return 0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)     {
            // prepare adjecency list
        vector<vector<int>> adj(numCourses);
        prepAdj(adj, prerequisites);
        vector<int> visited(numCourses, false);
        vector<int> bfsVisited(numCourses, false);
        // start DFS traversal starting from 1
        for(int i=0;i<numCourses;++i) {
            if(!visited[i] && isCyclic(adj, visited, bfsVisited, i)) {
                return false;
            }    
        } 
        return true;
    }
};