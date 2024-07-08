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
        int maxRotateFunction(vector<int>& nums) {
            int sum = 0;
            for(int num : nums)
                sum += num;
            int f = 0;
            for(int i = 0; i < nums.size(); i++)
                f += i * nums[i];
            int ans = f;
            for(int i = nums.size() - 1; i > 0; i--)
                ans = max(f += sum - nums[i] * nums.size(), ans);
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

        cout << solution.maxRotateFunction(nums) << endl;
    }
    
    return 0;
}