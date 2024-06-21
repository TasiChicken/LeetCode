#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
    vector<int> set;
    unordered_map<int, int> mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())
            return false;

        mp[val] = set.size();
        set.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())
            return false;

        mp[set.back()] = mp[val];
        set[mp[val]] = set.back();
        set.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return set[rand() % set.size()];
    }
};