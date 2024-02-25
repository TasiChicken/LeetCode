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
    int minPatches(vector<int>& nums, int n) {
        unsigned int ans = 0, bound = 1, idx = 0;
        while(bound <= n)
            if(idx < nums.size() && nums[idx] <= bound)
                bound += nums[idx++];
            else ans++, bound <<= 1;
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
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.minPatches(nums, n) << endl;
    }
    
    return 0;
}