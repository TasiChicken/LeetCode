#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> area;
    vector<vector<int>> rects;
    int rand_rect(){
        int num = rand() % area.back();
        if(num < area[0]) return 0;

        int l = 1, r = area.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(area[mid] > num) 
                if(area[mid - 1] <= num)
                    return mid;
                else r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
public:
    Solution(vector<vector<int>>& rects) {
        for(auto& r : rects){
            this->rects.push_back(r);
            area.push_back(area.size() ? area.back() : 0);
            area.back() += (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
        }
    }
    
    vector<int> pick() {
        auto rect = rects[rand_rect()];
        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);
        return {x, y};
    }
};