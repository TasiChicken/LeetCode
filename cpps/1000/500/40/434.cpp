#include <iostream>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        if(s.empty()) return 0;
        
        int cnt = s[0] != ' ';
        for(int i = 0; i < s.size() - 1; i++)
            cnt += s[i] == ' ' && s[i + 1] != ' ';
        return cnt;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        getline(cin, s);

        cout << solution.countSegments(s) << endl;
    }
    
    return 0;
}