#include <iostream>
#include <vector>
#include <set>
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
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff, int sa) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            auto r = s.insert(nums[i]);

            if(!r.second) return true;
            if(r.first != s.begin() && nums[i] - *(prev(r.first)) <= valueDiff) return true;
            if(++r.first != s.end() && *r.first - nums[i] <= valueDiff) return true;

            if(i >= indexDiff) s.erase(nums[i - indexDiff]);
        }
        return false;
    }
/*Optimized Solution 
    int getKey(int num, int valueDiff){
        return (num / (valueDiff + 1)) - (num < 0);
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<int, int> bucket;
        for(int i = 0; i < nums.size(); i++){
            int bKey = getKey(nums[i], valueDiff);
            if(!bucket.insert(pair<int, int>(bKey, nums[i])).second) return true;

            auto it = bucket.find(bKey + 1);
            if(it != bucket.end() && it->second - nums[i] <= valueDiff) return true;
            it = bucket.find(bKey - 1);
            if(it != bucket.end() && nums[i] - it->second <= valueDiff) return true;

            if(i >= indexDiff) bucket.erase(getKey(nums[i - indexDiff], valueDiff));
        }
        return false;
    }
*/
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);
        int indexDiff, valueDiff;
        cout << "indexDiff = ";
        cin >> indexDiff;
        cout << "valueDiff = ";
        cin >> valueDiff;
        cout << solution.containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff) << endl;
    }
    
    return 0;
}