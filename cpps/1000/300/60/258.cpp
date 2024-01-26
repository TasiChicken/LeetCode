#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return --num % 9 + 1;
    }
};

int main() {
    while(true) {
        Solution solution;
        int num;
        cout << "num = ";
        cin >> num;
        cout << solution.addDigits(num) << endl;
    }
    
    return 0;
}