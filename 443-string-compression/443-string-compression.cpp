class Solution {
public:
    int compress(vector<char>& a) {
        int ans = 0; // to store length of encoded array
        int ptr = 0; // ptr in original array to keep track where to push element
        
        for(int i=0;i<a.size();i++) {
            int count = 1;
            while(i+1<a.size() && a[i] == a[i+1]) {
                count++;
                i++;
            }

            a[ptr++] = a[i-count+1];
            ans++;
            
            if(count > 1) {
                string str = to_string(count);
                for(auto ch:str) {
                    a[ptr++] = ch;
                    ans++;
                }
            } 
        }
        
        return ans;
    }
};