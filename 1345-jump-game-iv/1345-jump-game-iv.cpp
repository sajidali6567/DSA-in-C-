class Solution {
public:
    map<int, vector<int>> mp;
    vector<bool> visited;
    int minJumps(vector<int>& arr) {
        visited.resize(arr.size(), false);
        
        for(int i=0;i<arr.size();i++) {
            mp[arr[i]].push_back(i);
        }
        
        queue<int> q;
        q.push(0);
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int index = q.front();q.pop();
                if(index <0 || index >= arr.size() || visited[index]) continue;
                
                visited[index] = true;
                
                if(index == arr.size()-1) return level;
                
                q.push(index+1); q.push(index-1);
                for(auto x:mp[arr[index]]) {
                    if(x == index) continue;
                    q.push(x);
                }
                mp[arr[index]].clear();
            }
            level++;
        }
        
        return -1;
    }
};