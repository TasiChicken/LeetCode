#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for(int i = s.length() - 1; i >= 0; i--)
            if(s[i] != ' ') ans++;
            else if(ans) return ans;
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        cout << solution.lengthOfLastWord(s);
    }
    
    return 0;
}