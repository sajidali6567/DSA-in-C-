class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> cnt(n);
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        priority_queue<long long, vector<long long>, greater<long long>> av;
        for(long long i=0;i<n;i++) av.push(i);
        
        for(auto meeting:meetings) {
            while(!pq.empty() && pq.top().first <= meeting[0]) {
                long long room = pq.top().second;  
                cout << meeting[0] << " " << meeting[1] << endl;
                pq.pop();
                av.push(room);
            }
            if(!av.empty()) {
                long long top = av.top(); av.pop();
                cnt[top]++; 
                pq.push({meeting[1], top});
            } else {
                long long room = pq.top().second;   
                long long diff = pq.top().first-meeting[0]; pq.pop();
                pq.push({meeting[1]+diff, room});
                cnt[room]++; 
            } 
        }
        
        long long maxIndex = 0, max = 0;
        for(long long i=0;i<cnt.size();i++) {
            if(cnt[i] > max) {
                maxIndex = i;
                max = cnt[i];
            }
        }
        return maxIndex;
    }
};