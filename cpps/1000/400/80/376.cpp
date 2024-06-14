#include <iostream>
#include <vector>

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
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 1, tan = 0;
        for(int i = 1; i < nums.size(); i++)
            if(tan == 0 && nums[i] != nums[i - 1] ||
            tan == 1 && nums[i] < nums[i - 1] ||
            tan == -1 && nums[i] > nums[i - 1])
                ans++, tan = nums[i] > nums[i - 1] ? 1 : -1;
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

        cout << solution.wiggleMaxLength(nums) << endl;
    }
    
    return 0;
}