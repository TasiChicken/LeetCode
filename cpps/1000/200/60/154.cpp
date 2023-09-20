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
    int recursion(vector<int>& nums, int l, int r) {
        int m;
        while(l < r)
            if(nums[m = l + r >> 1] < nums[m - 1]) return nums[m];
            else if(nums[m] > nums[0]) l = m + 1;
            else if(nums[m] < nums[0]) r = m - 1;
            else return min(recursion(nums, l, m - 1), recursion(nums, m + 1, r));
        return nums[r];
    }
public:
    int findMin(vector<int>& nums) {
        int r = nums.size() - 1;
        if(nums[0] < nums[r]) return nums[0];
        return recursion(nums, 1, r);
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