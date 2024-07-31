#include <iostream>

using namespace std;

class Solution {
    int mp[26 * 2];
public:
    int longestPalindrome(string s) {
        for(int i = 0; i < 26 * 2; i++)
            mp[i] = 0;

        for(char c : s)
            mp[(c >= 'a' && c <= 'z') ? 26 + c - 'a' : c - 'A']++;

        int ans = 0, mid = 0;
        for(int i = 0; i < 26 * 2; i++)
            ans += mp[i] >> 1, mid |= mp[i] & 1;
        return ans * 2 + mid;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;

        cout << solution.longestPalindrome(s) << endl;
    }
    
    return 0;
}