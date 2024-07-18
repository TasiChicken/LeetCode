#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> parse_(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}

class Solution {
    vector<unordered_set<int>> ks;
    unordered_map<int, int> mp;
    bool recursion(vector<int>& stones, int i, int k){
        if(i == stones.size() - 1) return true;
        if(ks[i].find(k) != ks[i].end()) return false;
        ks[i].insert(k);
        
        for(int j = k + 1; j > max(0, k - 2); j--)
            if(mp.find(stones[i] + j) != mp.end())
                if(recursion(stones, mp[stones[i] + j], j))
                    return true;
        return false;
    }
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        
        for(int i = 0; i < stones.size(); i++)
            mp[stones[i]] = i;
        ks = vector<unordered_set<int>>(stones.size());

        return recursion(stones, 1, 1);
    }
};



int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "stones = ";
        cin >> s;
        auto stones = parse_(s);
        
        cout << solution.canCross(stones) << endl;
    }
    
    return 0;
}