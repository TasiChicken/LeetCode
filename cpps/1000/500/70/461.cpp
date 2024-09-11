#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        y = 0;
        while(x){
            x &= x - 1;
            y++;
        }
        return y;
    }
};

int main() {
    while(true) {
        Solution solution;
        int x, y;
        cout << "x = ";
        cin >> x;
        cout << "y = ";
        cin >> y;

        cout << solution.hammingDistance(x, y) << endl;
    }
    
    return 0;
}