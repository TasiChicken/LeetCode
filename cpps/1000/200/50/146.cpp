#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
    int size = 0, capacity;
    list<pair<int, int>> data;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto r = mp.find(key);
        if(r == mp.end()) return -1;

        data.splice(data.begin(), data, r->second);
        return r->second->second;
    }
    
    void put(int key, int value) {
        auto r = mp.find(key);
        if(r != mp.end()) {
            data.splice(data.begin(), data, r->second);
            r->second->second = value;
            return;
        }

        if(size++ == capacity){
            mp.erase(data.back().first);
            data.pop_back();
            size--;
        }

        data.push_front({key, value});
        mp[key] = data.begin();
    }
};