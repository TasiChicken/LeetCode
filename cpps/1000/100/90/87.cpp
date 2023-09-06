#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<string, bool> result;
public:
    bool isScramble(string s1, string s2, bool checked = false) {
        int len = s1.length();
        if(s1 == s2 || checked && len < 4) return true;
        auto r = result.find(s1 + s2);
        if(r != result.end()) return r->second;
        cout << s1 << '\t' <<s2 <<endl;

        unordered_map<char, short> front, back;
        for(int i = 0; i < len; ){
            if(!(++front[s1[i]])) front.erase(s1[i]);
            if(!(++back[s1[i]])) back.erase(s1[i]);
            
            if(!(--front[s2[i]])) front.erase(s2[i]);
            i++;
            if(!(--back[s2[len - i]])) back.erase(s2[len - i]);
            if(i == len) break;

            if(front.empty() 
            && isScramble(s1.substr(0, i), s2.substr(0, i), true) 
            && isScramble(s1.substr(i), s2.substr(i)))
                return result[s1 + s2] = true;
            if(back.empty() 
            && isScramble(s1.substr(0, i), s2.substr(len - i, i), true)
            && isScramble(s1.substr(i), s2.substr(0, len - i)))
                return result[s1 + s2] = true;
        }
        return result[s1 + s2] = front.empty() && len < 4;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s1, s2;
        cout << "s1 = ";
        cin >> s1;
        cout << "s2 = ";
        cin >> s2;

        cout << solution.isScramble(s1, s2) << endl;
    }
    
    return 0;
}