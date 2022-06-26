class Solution {
public:
    int compress(vector<char>& a) {
        int ans = 0;
        vector<char> res;

        for(int i=0;i<a.size();i++) {
            int count = 1;
            while(i+1<a.size() && a[i] == a[i+1]) {
                count++;
                i++;
            }

            res.push_back(a[i]);
            ans++;
            
            if(count > 1) {
                string str = to_string(count);
                for(auto x:str) {
                    res.push_back(x);
                    ans++;
                }
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