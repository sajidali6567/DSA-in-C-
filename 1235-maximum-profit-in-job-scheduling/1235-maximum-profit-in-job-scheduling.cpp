class Solution {
public:
    int findMaxProfit(vector<vector<int>>& jobs) {
        //  priority queue will store {end,profit}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int maxProfit = 0;
        for(auto job:jobs) {
            int start = job[0], end = job[1], profitt = job[2];
            // remove all the jobs from the queue whose end time is less than or equal to current job's start time
            // but maxProfit should be stored for the chains we are throwing away
            // concept: the chains we are throwing away is not conflicting with job i then it will not conflict with the any other      jobs after i, we do not need these chains anymore if we keep the maxProfit we are gaining from these chains
            while(!pq.empty() && pq.top().first <= start) {
                maxProfit = max(maxProfit, pq.top().second);
                pq.pop();
            }
            // add current jobs into the most profitable chain and push it into the queue
            pq.push({end, profitt+maxProfit});
        }
        
        // check the queue for the maxProfit
        while(!pq.empty()) {
            maxProfit = max(maxProfit, pq.top().second);
            pq.pop();
        }
        return maxProfit;       
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for(int i=0;i<profit.size();i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        return findMaxProfit(jobs);
    }
};