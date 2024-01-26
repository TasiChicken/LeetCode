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

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), ans = (1 + n) * n >> 1;
        for(int num : nums)
            ans -= num;
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

        cout << solution.missingNumber(nums) << endl;
    }
    
    return 0;
}