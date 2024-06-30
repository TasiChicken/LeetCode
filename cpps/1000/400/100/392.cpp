#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0;
        for(int ti = 0; si < s.size() && ti < t.size(); si++, ti++){
            while(ti < t.size() && s[si] != t[ti]) ti++;
            if(ti == t.size()) return false;
            if(si == s.size() - 1) return true;
        }
        return si == s.size();
    }
};

int main() {
    while(true) {
        Solution solution;
        string s, t;
        cout << "s = ";
        cin >> s;
        cout << "t = ";
        cin >> t;

        cout << solution.isSubsequence(s, t) << endl;
    }
    
    return 0;
}