#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parse(string s){
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
    int longestConsecutive(vector<int>& nums) {
        int count = 1, ans = 0, s = nums.size();
        if(!s) return 0;

        sort(nums.begin(), nums.end());
        for(int i = 1; i < s; i++)
            if(nums[i] == nums[i - 1] + 1) count++; 
            else if(nums[i] != nums[i - 1]) ans = max(ans, count), count = 1;
        return max(ans, count);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse(s);

        cout << solution.longestConsecutive(nums) << endl;
    }
    
    return 0;
}