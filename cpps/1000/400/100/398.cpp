#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int, vector<int>> mp;
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        auto& table = mp[target];
        return table[rand() % table.size()];
    }
};