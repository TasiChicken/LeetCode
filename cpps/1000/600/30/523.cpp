#include <bits/stdc++.h>

using namespace std;

vector<int> parse_(string s) {
    vector<int> v;
    int last = 1;
    for (int i = 2; i < s.length(); i++)
        if (s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prev_idx;
        prev_idx[0] = -1;
        
        int mod = 0;
        for(int i = 0; i < nums.size(); i++){
            mod = (mod + nums[i]) % k;
            
            if(prev_idx.find(mod) != prev_idx.end()){
                if(i - prev_idx[mod] >= 2) return true;
            }
            else prev_idx[mod] = i;
        }
        return false;
    }
};

int main() {
    while (true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);
        int k;
        cout << "k = ";
        cin >> k;

        cout << solution.checkSubarraySum(nums, k) << endl;
    }

    return 0;
}