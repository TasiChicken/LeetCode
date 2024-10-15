#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        long long mask = num;
        while(mask & mask - 1)
            mask = mask & mask - 1;
        return ~num & ((mask << 1) - 1);
    }
};

int main() {
    while(true) {
        Solution solution;
        int num;
        cout << "num = ";
        cin >> num;

        cout << solution.findComplement(num) << endl;
    }
    
    return 0;
}