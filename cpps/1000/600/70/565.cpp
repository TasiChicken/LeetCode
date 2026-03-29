#include <bits/stdc++.h>

using namespace std;

class Solution {
    int count(vector<int>& nums, int idx){
        if(nums[idx] == -1) return 0;
        int n = nums[idx];
        nums[idx] = -1;
        return 1 + count(nums, n);
    }
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)        
            ans = max(ans, count(nums, i));

        return ans;
    }
};

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

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        auto nums = parse_(s);

        cout << solution.arrayNesting(nums) << endl;
    }
    
    return 0;
}