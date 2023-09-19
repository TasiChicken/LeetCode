#include <iostream>

using namespace std;

class Solution {
    string getSub(string& s, int& start){
        if(start < 0) return "";
        if(s[start] == ' ') return getSub(s, --start);

        int l = 1;
        while(start-- && s[start] != ' ') l++;
        return s.substr(start + 1, l);
    }
public:
    string reverseWords(string s) {
        int start = s.length();
        string ans, word;
        ans.reserve(start);
        
        while(start >= 0){
            word = getSub(s, --start);
            if(word != "") ans += word + ' ';
        }
        ans.pop_back();
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        getline(cin, s);

        cout << solution.reverseWords(s) << endl;
    }
    
    return 0;
}