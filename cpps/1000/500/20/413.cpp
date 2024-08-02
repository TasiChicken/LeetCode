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
    vector<int> dp = vector<int>(1, 1);
    int subarray_num(int cnt){
        if(cnt < 0) return 0;
        if(cnt < dp.size()) return dp[cnt];

        dp.push_back(subarray_num(cnt - 1) + cnt + 1);
        return dp.back();
    }
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, cnt = 1, sub = 0;
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] - nums[i - 1] != sub){
                ans += subarray_num(cnt - 3);
                sub = nums[i] - nums[i - 1];
                cnt = 2;
            }
            else cnt++;
        ans += subarray_num(cnt - 3);
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

        cout << solution.numberOfArithmeticSlices(nums) << endl;
    }
    
    return 0;
}