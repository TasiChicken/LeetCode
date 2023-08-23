#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;

        for(int num : nums){
            sum += num;
            ans = max(ans, sum);
            sum = max(0, sum);
        }

        return ans;
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

        cout << solution.maxSubArray(nums) << endl;
    }
    
    return 0;
}