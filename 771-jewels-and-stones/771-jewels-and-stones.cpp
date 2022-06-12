class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int>mp;
        for(int i=0; i < jewels.size(); i++) {
            mp[jewels[i]]++;
        }
        int count=0;
        for(int j=0; j< stones.size(); j++) {
            if(mp[stones[j]] != 0)
                count++; 
        }
        return count;
        
    }
};