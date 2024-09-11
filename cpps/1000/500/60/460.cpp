#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
    int size, capacity, smallest;
    unordered_map<int, list<pair<int, int>>> freq;
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> mp;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        auto& tar = mp[key];
        int val = (*tar.second).second;
        freq[tar.first].erase(tar.second);
        tar.first++;
        freq[tar.first].emplace_front(key, val);
        tar.second = freq[tar.first].begin();

        if(freq[smallest].empty()) smallest++;
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(size == capacity){
                mp.erase(freq[smallest].back().first);
                freq[smallest].pop_back();
            }
            else size++;

            freq[1].emplace_front(key, value);
            mp[key] = {1, freq[1].begin()};
            smallest = 1;
            return;
        }

        auto& tar = mp[key];
        freq[tar.first].erase(tar.second);
        tar.first++;
        freq[tar.first].emplace_front(key, value);;
        tar.second = freq[tar.first].begin();

        if(freq[smallest].empty()) smallest++;
    }
};

int main(){
    LFUCache lfu(2);
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    cout << lfu.get(1);      // return 1
                    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                    // cache=[3,1], cnt(3)=1, cnt(1)=2
    cout << lfu.get(2);      // return -1 (not found)
    cout << lfu.get(3);      // return 3
                    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                    // cache=[4,3], cnt(4)=1, cnt(3)=2
    cout << lfu.get(1);      // return -1 (not found)
    cout << lfu.get(3);      // return 3
                    // cache=[3,4], cnt(4)=1, cnt(3)=3
    cout << lfu.get(4);      // return 4
                    // cache=[4,3], cnt(4)=2, cnt(3)=3
}