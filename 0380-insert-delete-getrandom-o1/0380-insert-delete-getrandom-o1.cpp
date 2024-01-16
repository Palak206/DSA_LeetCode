class RandomizedSet {
public:
    set<int>st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val) != st.end())
            return false;
        
        st.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(st.find(val) == st.end())
            return false;
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        // doing mod to get in range [0, st.size()-1]
        int pos = rand() % st.size();
        // std::next returns an iterator pointing to the element after being advanced by certain no. of positions.
        return *next(st.begin(), pos);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */