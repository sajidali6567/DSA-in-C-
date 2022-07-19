class Solution {
public:
    void DFS(unordered_map<string, multiset<string>>& adj, string source, map<pair<string,string>, int>& countN, vector<string>& res) {
        for(auto node:adj[source]) {
            if(countN[{source, node}] != 0) {
                countN[{source, node}]--;
                DFS(adj, node, countN, res);
            }
        }
        res.push_back(source);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string, multiset<string>> adj;
        map<pair<string,string>, int> countN;
        // prepare adjacency list
        for(auto ticket:tickets) {
            adj[ticket[0]].insert(ticket[1]);
            countN[{ticket[0], ticket[1]}]++;
        }
        
        vector<string> res;
        DFS(adj, "JFK", countN, res);
        reverse(res.begin(), res.end());
        return res;
    }
};