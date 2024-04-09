#include <iostream>
#include <vector>
#include <algorithm>

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

void print(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> mp(nums.size(), {-1, -1});
        int ansIdx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(mp[i].first > mp[ansIdx].first) ansIdx = i;

            for(int j = i + 1; j < nums.size(); j++)
                if(nums[j] % nums[i] == 0 && mp[j].first <= mp[i].first)
                    mp[j] = {mp[i].first + 1, i};
        }
        
        vector<int> ans;
        while(ansIdx >= 0){
            ans.push_back(nums[ansIdx]);
            ansIdx = mp[ansIdx].second;
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);

        print(solution.largestDivisibleSubset(nums));
    }
    
    return 0;
}