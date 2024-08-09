#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        string keys = "zowhufxsgi";
        unordered_map<char, int> mp;
        for(int i = 0; i < keys.size(); i++)
            mp[keys[i]] = i;

        vector<int> tb(10);
        for(char c : s)
            if(mp.find(c) != mp.end())
                tb[mp[c]]++;

        tb[1] -= tb[0] + tb[2] + tb[4];
        tb[3] -= tb[8];
        tb[5] -= tb[4];
        tb[7] -= tb[6];
        tb[9] -= tb[5] + tb[6] + tb[8];

        string ans;
        for(int i = 0; i < 10; i++)
            ans += string(tb[i], '0' + i);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;

        cout << solution.originalDigits(s) << endl;
    }
    
    return 0;
}