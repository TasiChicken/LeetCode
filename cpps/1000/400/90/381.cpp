#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class RandomizedCollection {
    vector<int> col;
    unordered_map<int, unordered_set<int>> mp;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        mp[val].insert(col.size());
        col.push_back(val);
        return mp[val].size() == 1;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())
            return false;

        int posi = *mp[val].begin();
        col[posi] = col.back();
        mp[val].erase(posi);
        mp[col.back()].insert(posi);
        col.pop_back();
        mp[col[posi]].erase(col.size());
        if(mp[val].empty()) mp.erase(val);
         
        return true;
    }
    
    int getRandom() {
        return col[rand() % col.size()];
    }
};

int main(){
    RandomizedCollection r;
    int i = 0;
    int num[] = {1,1,2,1,2,2,1,2,2,2};
    for(int j = 0; j < 6; j++, i++)
        r.insert(num[i]);
    for(int j = 0; j < 4; j++, i++)
        r.remove(num[i]);
    cout << r.getRandom() << endl;
    return 0;
}