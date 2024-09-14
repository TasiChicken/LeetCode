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

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + (nums.size() >> 1), nums.end());
        int mid = nums[nums.size() >> 1];
        int ans = 0;
        for(int n : nums)
            ans += abs(n - mid);
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

        cout << solution.minMoves2(nums) << endl;
    }
    
    return 0;
}