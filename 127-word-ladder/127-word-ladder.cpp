class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // To store all the words in a dictionary, will facilitate to search a word in O(1)
        unordered_set<string> dict(wordList.begin(), wordList.end());
        // if endWord is not present in the dictionary return 0
        if(dict.find(endWord) == dict.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int depth = 1;
        dict.erase(beginWord);
        // level order traversal line by to to get the depth of endWord
        while(!q.empty()) {
            int count = q.size();
            while(count--) {
                string cur = q.front(); q.pop();
                // traverse all the character one by one and replace it with all possible
                // charcaters except the one it is
                for(int i=0;i<cur.length();i++) {
                    string temp = cur;
                    for(char x = 'a'; x<='z';x++) {
                        temp[i] = x;
                        // check it temp is endWord
                        if(temp == endWord) {
                            return depth+1;
                        }
                        //  check if temp is present in wordList
                        if(dict.find(temp) != dict.end()) {
                            q.push(temp);
                            dict.erase(temp);
                        }
                    }
                }
            }
            depth+=1;
        }
        return 0;
    }
};