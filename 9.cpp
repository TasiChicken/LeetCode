#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);

        int len = s.length();
        for(int i = 0; i < len; i++) 
            if(s[i] != s[len - i - 1]) return false;
        return true;
    }
};

int main()
{
    Solution solution;

    while(true) {
        int x;
        cout << "x = ";
        cin >> x;
        cout << solution.isPalindrome(x) << endl;
    }
    
    return 0;
}