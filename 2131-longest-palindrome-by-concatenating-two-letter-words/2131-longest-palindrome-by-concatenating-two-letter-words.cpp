class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        int flag = 0;   // to keep track if element with same letters are chosen, we can take only one
        cout << words.size() << endl;
        map<string, int> dict;
        for(auto word:words) {
            dict[word]++;
        }

        for(auto x:dict) {
            // cout << x.first << " " << x.second << endl;
            string word = x.first;
            if(word[0] == word[1]) {
                if(x.second&1) {
                    ans += (x.second-1)*2;
                    flag = 1;
                } else {
                    ans += (x.second)*2;
                }
                dict.erase(word);
            } else {
                string temp(word);
                reverse(word.begin(), word.end());
                if(dict.find(word) != dict.end()) {
                    int mini = min(dict[word], dict[temp]);
                    dict.erase(word);
                    dict.erase(temp);
                    ans += 4*mini;
                }
            }
            cout << ans << endl;
        }
        if(flag) ans+=2;
        return ans;
    }
};