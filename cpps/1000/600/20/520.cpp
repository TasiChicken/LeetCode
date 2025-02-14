#include <bits/stdc++.h>

using namespace std;

#define is_upper(x) ((x) >= 'A' && (x) <= 'Z')
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() < 2) return true;

        bool u = is_upper(word[1]);
        if(!is_upper(word[0]) && u) return false;

        for(int i = 2; i < word.size(); i++)
            if(is_upper(word[i]) ^ u) return false;
        return true;
    }
};

int main() {
    while(true) {
        Solution solution;
        string word;
        cout << "word = ";
        cin >> word;

        cout << solution.detectCapitalUse(word) << endl;
    }
    
    return 0;
}