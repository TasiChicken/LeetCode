#include <iostream>
#include <vector>
#include <unordered_map>

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
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long long, int>> dp(nums.size());
        int ans = 0;

        for(int i = 1; i < nums.size(); i++)
            for(int j = 0; j < i; j++){
                long long diff = (long long)nums[i] - nums[j];
                if(dp[j].find(diff) != dp[j].end())
                    ans += dp[j][diff], dp[i][diff] += dp[j][diff];
                dp[i][diff]++;;
            }

        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        auto nums = parse_(s);

        cout << solution.numberOfArithmeticSlices(nums) << endl;
    }
    
    return 0;
}