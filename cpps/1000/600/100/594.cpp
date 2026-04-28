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
    int findLHS(vector<int>& nums) {
        map<int, int> mp;
        for(int n : nums)
            mp[n]++;

        auto it = mp.begin();
        auto prev = it;
        it++;

        int ans = 0;
        while (it != mp.end()){
            if(it->first - prev->first == 1)
                ans = max(ans, it->second + prev->second);
            prev = it;
            it++;
        }

        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        auto nums = parse_(s);

        cout << solution.findLHS(nums) << endl;
    }
    
    return 0;
}