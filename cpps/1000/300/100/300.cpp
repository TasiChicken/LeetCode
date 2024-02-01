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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int num : nums)
            if(ans.empty() || num > ans.back()) ans.push_back(num);
            else if(ans[0] >= num) ans[0] = num;
            else{
                int l = 1, r = ans.size() - 1, m;
                while(l <= r){
                    m = l + r >> 1;
                    if(ans[m - 1] < num) 
                        if(ans[m] >= num) break;
                        else l = m + 1;
                    else r = m - 1;
                }
                ans[m] = num;
            }
        return ans.size();
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);

        cout << solution.lengthOfLIS(nums) << endl;
    }
    
    return 0;
}