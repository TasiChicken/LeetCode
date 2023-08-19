#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string s = countAndSay(n - 1);
        int len = s.length();
        
        string ans = "";
        int last = 0;
        for(int i = 0; i < len; i++)
            if(s[i] != s[last]) {
                ans += to_string(i - last) + s[last];
                last = i;
            }
        return ans + to_string(len - last) + s[last];
    }
};

int main() {
    Solution solution;

    while(true) {
        int n;
        cout << "n = ";
        cin >> n;
        cout << solution.countAndSay(n) << endl;
    }
    
    return 0;
}