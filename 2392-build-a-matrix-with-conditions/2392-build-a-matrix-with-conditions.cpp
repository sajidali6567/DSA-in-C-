class Solution {
public:
    // void print(vector<int>& vec) {
    //     for(auto x:vec) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    
    // finds index of x in vector vec
    int find(int x, vector<int>& vec) {
        for(int i=0;i<vec.size();i++) {
            if(vec[i] == x)
                return i;
        }
        return -1;
    }
    
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
        
        vector<vector<int>> rowAdj(k+1);
        vector<int> rowIndegree(k+1, 0);
        for(auto rowCondition:rowConditions) {
            rowAdj[rowCondition[0]].push_back(rowCondition[1]);
            rowIndegree[rowCondition[1]]++;
        } // print(rowIndegree);
        
        vector<int> rowTopo = kahnAlgo(rowAdj, rowIndegree); // print(rowTopo);
        if(rowTopo.size() != k) return {};    
        
        vector<vector<int>> colAdj(k+1);
        vector<int> colIndegree(k+1, 0);
        for(auto colCondition:colConditions) {
            colAdj[colCondition[0]].push_back(colCondition[1]);
            colIndegree[colCondition[1]]++;
        }
        vector<int> colTopo = kahnAlgo(colAdj, colIndegree); // print(colTopo);
        if(colTopo.size() != k) return {};   
        
        // Build Matrix using above two topological sortings
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for(int i=0;i<k;i++) {
            int j = find(rowTopo[i], colTopo);
            matrix[i][j] = rowTopo[i];
        }
        return matrix;
    }
};