        // // print adjacency list
        // for(auto i=1;i<=n;i++) {
        //     cout << i << " -> " ;
        //     for(auto x:adj[i]) {
        //         cout << x.first << " ";
        //     }
        //     cout << endl;
        // }
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& time, int n, int src) {
        
        // prepare adjacency list
        vector< vector<pair<int, int>> > adj(n+1);
        for(int i=0;i<time.size();i++) {
            adj[time[i][0]].push_back({time[i][1], time[i][2]});
        }

        vector<int> visited(n+1, false);
        vector<int> dist(n+1, 1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // start BFS with src
        dist[src] = 0;
        visited[src] = true;
        pq.push({0, src});
        while(!pq.empty()) {
            int u = pq.top().second; int uDist = pq.top().first; pq.pop();
            visited[u] = true;
            for(auto v:adj[u]) {
                if(!visited[v.first] && uDist + v.second < dist[v.first]) {
                    dist[v.first] = uDist + v.second;
                    pq.push({dist[v.first], v.first});
                }
            }
        }
        int ans = *max_element(dist.begin()+1, dist.end());
        return (ans==1e9)?-1:ans;
    }
};