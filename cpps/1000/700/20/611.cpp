#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int cnt = 0;
        for(int i = 2; i < nums.size(); i++){
            int l = 0, r = i - 1;

            while(l < r){
                if(nums[l] + nums[r] > nums[i]){
                    cnt += r - l;
                    r--;
                }
                else{
                    l++;
                }
            }
        }

        return cnt;
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

        cout << solution.triangleNumber(nums) << endl;
    }
    
    return 0;
}