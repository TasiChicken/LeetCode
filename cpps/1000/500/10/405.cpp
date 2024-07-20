#include <iostream>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        string ans = "";
        for(int i = 7; i >= 0; i--){
            int n = ((num & (0xf << (i * 4))) >> (i * 4)) & 0xf;
            ans.push_back(n + (n > 9 ? 'a' - 10 : '0'));
        }

        int idx = 0;
        while(ans[idx] == '0' && idx < 7)
            idx++;
        return ans.substr(idx);
    }
};

int main() {
    while(true) {
        Solution solution;
        int num;
        cout << "num = ";
        cin >> num;

        cout << solution.toHex(num) << endl;
    }
    
    return 0;
}