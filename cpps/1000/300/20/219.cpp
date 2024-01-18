#include <iostream>
#include <vector>
#include <unordered_set>

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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> us;
        for(int i = 0; i < nums.size(); i++){
            if(us.find(nums[i]) != us.end())
                return true;
            us.insert(nums[i]);
            if(i >= k) us.erase(nums[i - k]);
        }
        return false;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);
        int k;
        cout << "k = ";
        cin >> k;
        cout << solution.containsNearbyDuplicate(nums, k) << endl;
    }
    
    return 0;
}