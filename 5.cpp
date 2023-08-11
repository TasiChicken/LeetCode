#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();

        int ansIndex = 0;
        int ansLen = 1;
        for(int i = 0; i < len - 1; i++) {
            int delta = 1;
            while(i - delta >= 0 && i + delta < len && s[i - delta] == s[i + delta]) 
                delta++;
            
            if(--delta * 2 + 1 > ansLen) {
                ansIndex = i - delta;
                ansLen = delta * 2 + 1;
            }

            delta = 0;
            while(i - delta >= 0 && i + delta + 1 < len && s[i - delta] == s[i + delta + 1]) 
                delta++;
            
            if(delta * 2 > ansLen) {
                ansIndex = i - delta + 1;
                ansLen = delta * 2;
            }
        }

        return s.substr(ansIndex, ansLen);
    }
};

int main()
{
    Solution solution;

    while(true){
        string s;
        cout << "s = ";
        cin >> s;
        cout << solution.longestPalindrome(s) << endl;
    }

    return 0;
}