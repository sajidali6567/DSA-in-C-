class RandomizedSet {
public:
    unordered_map<int, int> mp; // stores <val, index>
    vector<int> vec; // store<index, val>
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        mp[val] = vec.size();
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int valIndex  = mp[val];
        int lastIndex  = vec.size()-1;
        vec[valIndex ] = vec[lastIndex];
        mp[vec[lastIndex]] = valIndex ;
        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        // generate a random number between [0, vec.size())
        int index = (rand() % vec.size());
        return vec[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */