class Solution {
public:
    vector<vector<int>> jobs;
    vector<int> dp;
    int solve(int index, vector<int>& startTime) {
        if(index == jobs.size()) return 0;
        if(dp[index] != -1) return dp[index];
        
        int notPick = solve(index+1, startTime);
        int nextIndex = lower_bound(startTime.begin(), startTime.end(), jobs[index][1]) - startTime.begin();
        int pick = jobs[index][2] + solve(nextIndex, startTime);

        return dp[index] = max(pick, notPick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        dp.resize(profit.size(), -1);
        for(int i=0;i<profit.size();i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end()); // sorting jobs according to their start time, so it will be easy to find next job 
        for(int i=0;i<startTime.size();i++) {
            startTime[i] = jobs[i][0];  // since we want to search in startTime, we need to store it seperately
        }
        return solve(0, startTime);
    }
};