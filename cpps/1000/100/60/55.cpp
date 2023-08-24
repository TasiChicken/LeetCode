#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums, int index = 0, int start = 1) {
        if(index + nums[index] + 1 >= nums.size()) return true;
        if(nums[index] == 0) return false;
        int maxI = 0;
        for(int i = start; i <= nums[index]; i++)
            if(i + nums[i + index] > maxI + nums[maxI + index]) maxI = i;
        return maxI ? canJump(nums, index + maxI, nums[index] - maxI + 1) : false;
    }
};

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

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        vector<int> nums = parse(s);

        cout << solution.canJump(nums) << endl;
    }
    
    return 0;
}