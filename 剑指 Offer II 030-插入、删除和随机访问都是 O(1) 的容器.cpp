class RandomizedSet {
    vector<int> vals;
    map<int, int> locations;
    unsigned seed = time(0); 
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(locations.count(val) > 0)
        {
            return false;
        }
        vals.push_back(val);
        locations[val] = vals.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(locations.count(val) > 0)
        {
            int location = locations[val];
            vals[location] = vals[vals.size() - 1];
            locations[vals[vals.size() - 1]] = location;
            locations.erase(val);
            vals.pop_back();
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */