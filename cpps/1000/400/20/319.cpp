#include <iostream>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int i = 0;
        while(i * i <= n) i++;
        return i - 1;
    }   
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.bulbSwitch(n) << endl;
    }
    
    return 0;
}