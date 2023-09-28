#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mps;
        unordered_set<char> mpt;
        for(int i = 0; i < s.length(); i++)
            if(mps.find(s[i]) == mps.end())
                if(mpt.count(t[i])) return false;
                else mpt.insert(t[i]), mps[s[i]] = t[i];
            else if(mps[s[i]] != t[i]) return false;
        return true;
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

        cout << solution.isIsomorphic(s, t) << endl;
    }
    
    return 0;
}