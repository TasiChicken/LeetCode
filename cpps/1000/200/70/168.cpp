#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        int num = columnNumber, size = 0;
        while(num) size++, num /= 26;
        ans.resize(size);

        while(columnNumber) ans[--size] = 'A' + --columnNumber % 26, columnNumber /= 26;
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int columnNumber;
        cout << "columnNumber = ";
        cin >> columnNumber;

        cout << solution.convertToTitle(columnNumber) << endl;
    }
    
    return 0;
}