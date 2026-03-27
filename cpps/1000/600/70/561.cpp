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
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() / 2;
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += nums[i * 2];
        
        return sum;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        auto nums = parse_(s);

        cout << solution.arrayPairSum(nums) << endl;
    }
    
    return 0;
}