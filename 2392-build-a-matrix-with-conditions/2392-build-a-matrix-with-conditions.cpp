class Solution {
public:
    vector<int> kahnAlgo(vector<vector<int>>& adj, vector<int>& indegree) {
        queue<int> q;
        for(int i=1;i<indegree.size();i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            // travese all adjacent node to it
            for(auto v:adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }
        
        return topo;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<vector<int>> adj(k+1);
        vector<int> indegree(k+1, 0);
        for(auto rowCondition:rowConditions) {
            adj[rowCondition[0]].push_back(rowCondition[1]);
            indegree[rowCondition[1]]++;
        }
        
        vector<int> rowTopo = kahnAlgo(adj, indegree);
        if(rowTopo.size() != k) return {};    
        
        fill(adj.begin(), adj.end(), vector<int>(k+1, 0));
        fill(indegree.begin(), indegree.end(), 0);
        
        for(auto colCondition:colConditions) {
            adj[colCondition[0]].push_back(colCondition[1]);
            indegree[colCondition[1]]++;
        }
        
        vector<int> colTopo = kahnAlgo(adj, indegree);
        if(colTopo.size() != k) return {};   
        
        // Build Matrix using above two topological sortings
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for(int i=0;i<k;i++) {
            // find rowTopo[i] in colTopo array
            int j = std::find(colTopo.begin(), colTopo.end(), rowTopo[i]) - colTopo.begin();
            matrix[i][j] = rowTopo[i];
        }
        
        return matrix;
    }
};