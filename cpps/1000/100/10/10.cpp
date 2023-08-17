#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS = s.size(), lenP = p.size();

        bool emptyS = lenS == 0, emptyP = lenP == 0;
        if(emptyP) return emptyS;
        if(emptyS) {
            for(int i = 0; i < lenP; i += 2)
                if(i == lenP - 1 || p[i + 1] != '*') return false;

            return true;
        }

        if(lenP == 1) return lenS == 1 && (s[0] == p[0] || p[0] == '.');

        if(p[1] == '*') {
            int index = -1;
            while (index < lenS && (index < 0 || p[0] == '.' || s[index] == p[0]))
                if(isMatch(s.substr(++index), p.substr(2))) return true;
            return false;
        }
        else return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
    }
};

int main()
{
    Solution solution;

    while(true) {
        string s, p;
        cout << "s = ";
        cin >> s;
        cout << "p = ";
        cin >> p;

        cout << solution.isMatch(s, p) << endl;
    }
    
    return 0;
}