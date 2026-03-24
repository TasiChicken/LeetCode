#include <bits/stdc++.h>

using namespace std;

class Solution {
    void reverse(string& s, int from, int to){
        while(from < to)
            swap(s[from++], s[to--]);
    }
public:
    string reverseWords(string s) {
        int from = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == ' '){
                reverse(s, from, i - 1);
                from = i + 1;
            }
        reverse(s, from, s.size() - 1);
        return s;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        getline(cin, s);
        cout << solution.reverseWords(s) << endl;
    }
    
    return 0;
}