#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        int cnt = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '-') continue;

            res.push_back((s[i] >= 'a' && s[i] <= 'z') ? (s[i] - 'a' + 'A') : s[i]);
            if(++cnt == k) cnt = 0, res.push_back('-');
        }
        if(res.size() && res.back() == '-') res.pop_back();

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        int k;
        cout << "k = ";
        cin >> k;

        cout << solution.licenseKeyFormatting(s, k) << endl;
    }
    
    return 0;
}