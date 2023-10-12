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
    int rob(vector<int>& nums){
        int money[2][2] = { {0, 0}, {0, nums[0]} };
        for(int i = 1; i < nums.size(); i++)
            for(int j = 0; j < 2 && i + j < nums.size(); j++)
                money[j][1] = max(money[j][0] + nums[i], money[j][0] = money[j][1]);

        return max(money[0][1], money[1][1]);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse(s);
        cout << solution.rob(nums) << endl;
    }
    
    return 0;
}