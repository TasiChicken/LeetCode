#include <iostream>

using namespace std;

class Solution {
    int mp[26] = {};
public:
    int findSubstringInWraproundString(string s) {
        int cont = 1;
        mp[s[0] - 'a'] = 1;
        for(int i = 1; i < s.size(); i++){
            cont = (s[i] - 'a' == (s[i - 1] - 'a' + 1) % 26) ? cont + 1 : 1;
            mp[s[i] - 'a'] = max(mp[s[i] - 'a'], cont);
        }

        int ans = 0;
        for(int i = 0; i < 26; i++)
            ans += mp[i];
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        s = s.substr(1, s.size() - 2);

        cout << solution.findSubstringInWraproundString(s) << endl;
    }
    
    return 0;
}