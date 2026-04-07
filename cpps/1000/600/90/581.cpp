#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0, r = 0;

        int n = nums[0];
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] < n) r = i;
            else n = nums[i];

        if(r == 0) return 0;

        n = nums[r];
        for(int i = r - 1; i >= 0; i--)
            if(nums[i] > n) l = i;
            else n = nums[i];
        
        return r - l + 1;
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

        cout << solution.findUnsortedSubarray(nums) << endl;
    }
    
    return 0;
}