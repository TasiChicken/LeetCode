#include <iostream>
#include <vector>

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
/*Optimized Solution
    string longestPalindrome(string s) {
        int len = s.length() * 2 + 3;
        string m;
        m.reserve(len);
        m.push_back('!');
        for(char c : s) m.push_back('_'), m.push_back(c);
        m.push_back('_'), m.push_back('@');
        
        int ansIndex = 0, ansLen = 0, *p = new int[len], mid = 1, r = 1, mir;
        for(int i = 1; i < len - ansLen - 2; i++){
            int& cur = p[i];
            
            if(i < r){
                mir = mid * 2 - i;
                if(i + p[mir] < r){
                    cur = p[mir];
                    continue;
                }

                cur = r - i;
                if(i + p[mir] > r) continue;
            }
            else cur = 0;

            while(m[i + ++cur] == m[i - cur]);
            r = i + --cur;
            mid = i;

            if(cur > ansLen) ansIndex = i, ansLen = cur;
        }
        
        return s.substr(ansIndex - ansLen - 1 >> 1, ansLen);
    }
*/
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