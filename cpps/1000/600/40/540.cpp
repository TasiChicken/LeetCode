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
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() < 2 || nums[0] != nums[1]) return nums[0];
        if(nums.back() != nums[nums.size() - 1]) return nums.back();

        int l = 1, r = nums.size() - 1, mid;
        while(l < r){
            mid = l + r >> 1;
            if(nums[mid] == nums[mid ^ 1]) l = (mid | 1) + 1;
            else if(nums[mid] == nums[mid - 1] || nums[mid] == nums[mid + 1]) r = mid - 1;
            else return nums[mid];
        }
        
        return nums[l];
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);

        cout << solution.singleNonDuplicate(nums) << endl;
    }
    
    return 0;
}