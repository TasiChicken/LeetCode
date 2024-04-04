#include <iostream>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(!n) return 1;
        int num = 1;
        for(int i = 1; i < n; i++)
            num *= 10 - i;
        return 9 * num + countNumbersWithUniqueDigits(n - 1);
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;
        cout << solution.countNumbersWithUniqueDigits(n) << endl;
    }
    
    return 0;
}