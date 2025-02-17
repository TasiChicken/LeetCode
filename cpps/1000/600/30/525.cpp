#include <bits/stdc++.h>

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
    int findMaxLength(vector<int>& nums) {
        vector<int> pos, neg;
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i] ? 1 : -1;
            if(sum > 0){
                if(sum > pos.size()) pos.push_back(i);
                else ans = max(ans, i - pos[sum - 1]);
            }
            else if(sum < 0){
                if(-sum > neg.size()) neg.push_back(i);
                else ans = max(ans, i - neg[-sum - 1]);
            }
            else ans = max(ans, i + 1);
        }

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

        cout << solution.findMaxLength(nums) << endl;
    }
    
    return 0;
}