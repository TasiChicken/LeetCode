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
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        
        if(k == 0){
            unordered_map<int, int> mp;
            for(int n : nums)
                ans += (mp[n]++ == 1);
            return ans;
        }
        
        unordered_set<int> hash;
        int maxi = INT_MIN;
        for(int n : nums)
            hash.insert(n), maxi = max(maxi, n);
        
        int temp;
        for(auto it = hash.begin(); it != hash.end(); it++){
            temp = *it + k;
            if(temp > maxi) continue;
            if(hash.find(temp) != hash.end()) ans++;
        }

        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        cout << "nums = ";
        string s;
        cin >> s;
        auto nums = parse_(s);
        int k;
        cout << "k = ";
        cin >> k;

        cout << solution.findPairs(nums, k) << endl;
    }
    
    return 0;
}