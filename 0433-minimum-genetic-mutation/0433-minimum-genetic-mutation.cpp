class Solution {
public:
    int compareDiff(string& a, string& b) {
        int diff = 0;
        for(int i=0;i<a.size();i++) {
            if(a[i] != b[i])
                diff++;
        }
        return diff;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict (bank.begin(), bank.end());
        if(!dict.count(end)) return -1;
        
        queue<string> q;
        q.push(start);
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string node = q.front(); q.pop();
                if(node == end) {
                    return level;
                }

                for(auto gene:bank) {
                    if(compareDiff(gene, node) == 1) {
                        q.push(gene);
                    }
                }
                dict.erase(node);
            }
            ++level;
        }
        return -1;
    }
};