#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += k * 2)
            for(int j = i, l = min((int)s.size(), i + k) - 1; j < l; j++, l--)
                swap(s[j], s[l]);

        return s;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        s = s.substr(1, s.size() - 2);
        int k;
        cout << "k = ";
        cin >> k;

        cout << solution.reverseStr(s, k) << endl;
    }
    
    return 0;
}