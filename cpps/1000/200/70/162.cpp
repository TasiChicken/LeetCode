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
    int findPeakElement(vector<int>& nums) {
        int last = nums.size() -  1, l = 0, r = last, m;
        while(l < r)
            if((!(m = l + r >> 1) || nums[m] > nums[m - 1]) && (m == last || nums[m] > nums[m + 1])) return m;
            else if(nums[m] < nums[m + 1]) l = m + 1;
            else r = m - 1;
        return l;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse(s);

        cout << solution.findPeakElement(nums) << endl;
    }
    
    return 0;
}