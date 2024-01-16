#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string str = s + "0" + rev;

        int len = str.length(), tb[len];
        int last = tb[0] = 0;
        for(int i = 1, j = 0; i < len; )
            if(str[i] == str[j]){
                tb[i] = ++last;
                i++, j++;
            }
            else if(j) j = last = tb[j - 1];
            else tb[i++] = last = 0;
        
        rev.resize(len / 2 - last);
        return rev + s;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        cout << solution.shortestPalindrome(s) << endl;
    }
    
    return 0;
}