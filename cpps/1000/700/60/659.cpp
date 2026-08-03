#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int prev = nums[0];

        int _3 = 0, _2 = 0, _1 = 0;
        int new_3 = 0, new_2 = 0, new_1 = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == prev){
                if(_1 > 0) new_2++, _1--;
                else if(_2 > 0) new_3++, _2--;
                else if(_3 > 0) new_3++, _3--;
                else new_1++;

                continue;
            }

            if(_1 != 0 || _2 != 0) return false;

            if(nums[i] == prev + 1){
                _1 = new_1;
                _2 = new_2;
                _3 = new_3;
                new_1 = new_2 = new_3 = 0;
                prev = nums[i];
                i--;

                continue;
            }

            if(new_1 != 0 || new_2 != 0) return false;

            _1 = _2 = _3 = new_1 = new_2 = new_3 = 0;
            prev = nums[i];
            i--;
        }

        if(_2 != 0 || _1 != 0 || new_2 != 0 || new_1 != 0) return false;

        return true;
    }
};

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

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        auto nums = parse_(s);

        cout << solution.isPossible(nums) << endl;
    }
    
    return 0;
}