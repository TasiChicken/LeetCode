#include <bits/stdc++.h>

using namespace std;

#define MinHeap priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
class Solution {
    void push_heap(vector<int>& t, int p, int s, vector<unordered_map<int, int>>& mp, MinHeap& minHeap){
        int dis = abs(t[2] - p);
        dis = t[0] + min(dis, s - dis);
        
        if(mp[p].find(t[1]) != mp[p].end() && mp[p][t[1]] <= dis) return;

        mp[p][t[1]] = dis;
        minHeap.push({dis, t[1], p});
    }
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> pos(26);
        for(int i = 0 ; i < ring.size(); i++)
            pos[ring[i] - 'a'].push_back(i);
        
        MinHeap minHeap;
        for(int p : pos[key.back() - 'a'])
            minHeap.push({(int)key.size(), (int)key.size() - 1, p});

        vector<unordered_map<int, int>> mp(ring.size());
        while(minHeap.size()){
            auto t = minHeap.top();
            minHeap.pop();
            
            if(t[1] == -1) 
                return t[0];
            
            while(t[1] > 0 && key[t[1]] == key[t[1] - 1]) t[1]--;
            t[1]--;

            if(t[1] == -1) {
                push_heap(t, 0, ring.size(), mp, minHeap);
                continue;
            }

            for(int p : pos[key[t[1]] - 'a'])
                push_heap(t, p, ring.size(), mp, minHeap);
        }
        return -1;
    }
};

int main() {
    while(true) {
        Solution solution;
        string ring;
        cout << "ring = ";
        cin >> ring;
        string key;
        cout << "key = ";
        cin >> key;

        cout << solution.findRotateSteps(ring, key) << endl;
    }
    
    return 0;
}