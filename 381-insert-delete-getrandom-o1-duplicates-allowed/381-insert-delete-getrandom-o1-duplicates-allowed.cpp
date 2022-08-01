class RandomizedCollection {
public:
    unordered_map<int, set<int>> mp; // stores <val, index>
    vector<int> vec; // store<index, val>
    
    bool insert(int val) {
        bool isPresent = mp.find(val) == mp.end();
        mp[val].insert(vec.size());
        vec.push_back(val);
        return isPresent;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int valIndex  = *mp[val].begin();
        int lastIndex  = vec.size()-1;
        vec[valIndex ] = vec[lastIndex];
        if(lastIndex != valIndex) {
            mp[val].erase(valIndex);
            mp[vec[lastIndex]].erase(lastIndex);
            mp[vec[lastIndex]].insert(valIndex);
        } else {
            mp[vec[lastIndex]].erase(lastIndex);
            mp[vec[lastIndex]].insert(valIndex);
            mp[val].erase(valIndex);
        }
        
        
        
        vec.pop_back();
        
        if(mp[val].size() == 0) {
            mp.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        // generate a random number between [0, vec.size())
        int index = (rand() % vec.size());
        return vec[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */