#include <iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string con = s.substr(1) + s.substr(0, s.size() - 1);
        return con.find(s) != string::npos;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;

        cout << solution.repeatedSubstringPattern(s) << endl;
    }
    
    return 0;
}