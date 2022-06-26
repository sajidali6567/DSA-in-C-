class Solution {
public:
    int digit(int count) {
        int ans = 0;
        while(count != 0) {
            count /=10;
            ans++;
        }
        return ans;
    }
    int compress(vector<char>& a) {
        int ans = 0;
        vector<char> res;
        if(0 == a.size()-1) {
            res.push_back(a[0]);
            ans++;
        }
        for(int i=1;i<a.size();i++) {
            int count = 1;
            while(i<a.size() && a[i] == a[i-1]) {
                count++;
                i++;
            }
            if(count > 1) {
                ans += 1 + digit(count);
            } else {
                ans++;
            }
            res.push_back(a[i-1]);
            if(count > 1) {
                string str = to_string(count);
                for(auto x:str) {
                    res.push_back(x);
                }
            }
            if(i == a.size()-1) {
                res.push_back(a[i]);
                ans++;
            }
        }
        a.clear();
        for(auto x:res) {
            a.push_back(x);
            cout << x << " ";
        }
        return ans;
    }
};