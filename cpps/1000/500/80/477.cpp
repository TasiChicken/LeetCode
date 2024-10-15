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
    int totalHammingDistance(vector<int>& nums) {
        int mp[32][2];
        for(int i = 0; i < 32; i++)
            mp[i][0] = mp[i][1] = 0;

        for(int num : nums)
            for(int i = 0; i < 32; i++)
                mp[i][!!(num & (1 << i))]++;
        
        int ans = 0;
        for(int i = 0; i < 32; i++)
            ans += mp[i][0] * mp[i][1];
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

        cout << solution.totalHammingDistance(nums) << endl;
    }
    
    return 0;
}