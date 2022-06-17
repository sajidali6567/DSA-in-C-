class Solution {
public:
    void print(queue<string> q) {
        while(!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) == dict.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int level = 0;
        while(!q.empty()) {
            level += 1;
            int count = q.size();
            // print(q);
            while(count--) {
                string temp = q.front();q.pop();
                // traverse all adjecent nodes of temp (if they exist in the dict)
                for(int i=0;i<temp.size();i++) {
                    char orig = temp[i];
                    for(char ch='a';ch<='z';ch++) {
                        if(ch ==orig) continue;
                        temp[i] = ch;
                        // if temp is present in dict push into the queue
                        if(dict.find(temp) != dict.end()) {
                            if(temp == endWord) return level+1;
                            q.push(temp);
                            dict.erase(temp);
                        }
                    }
                    temp[i] = orig;
                }
            }
        }
        return 0;
    }
};