#include <bits/stdc++.h>

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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        mp[0]++;

        int tol = 0, res = 0;

        for(int n : nums){
            tol += n;
            
            if(mp.find(tol - k) != mp.end())
                res += mp[tol - k];
            
            mp[tol]++;
        }

        return res;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        auto nums = parse_(s);
        int k;
        cin >> k;

        cout << solution.subarraySum(nums, k) << endl;
    }
    
    return 0;
}