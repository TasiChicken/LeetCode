#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(char letter : columnTitle)
            ans = ans * 26 - 'A' + letter + 1;
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string columnTitle;
        cout << "columnTitle = ";
        cin >> columnTitle;

        cout << solution.titleToNumber(columnTitle) << endl;
    }
    
    return 0;
}