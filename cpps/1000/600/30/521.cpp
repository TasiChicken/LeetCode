#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.length(), b.length());
    }
};

int main() {
    while(true) {
        Solution solution;
        string a, b;
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;

        cout << solution.findLUSlength(a, b) << endl;
    }
    
    return 0;
}