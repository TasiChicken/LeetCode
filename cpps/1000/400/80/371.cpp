#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        return b ? getSum(a ^ b, (a & b) << 1) : a;
    }
};

int main() {
    while(true) {
        Solution solution;
        int a, b;
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;

        cout << solution.getSum(a, b) << endl;
    }
    
    return 0;
}