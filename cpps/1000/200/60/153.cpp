#include <iostream>
#include <vector>

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
    int findMin(vector<int>& nums) {
        int l = 1, r = nums.size() - 1, m;
        if(nums[0] < nums[r]) return nums[0];
        while(l < r)
            if(nums[m = l + r >> 1] < nums[m - 1]) return nums[m];
            else if(nums[m] > nums[0]) l = m + 1;
            else r = m - 1;
        return nums[r];
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse(s);
        
        cout << solution.findMin(nums) << endl;
    }
    
    return 0;
}