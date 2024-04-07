#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        return target <= x + y && target % gcd(x, y) == 0;
    }
};

int main() {
    while(true) {
        Solution solution;
        int x, y, target;
        cout << "x = ";
        cin >> x;
        cout << "y = ";
        cin >> y;
        cout << "target = ";
        cin >> target;

        cout << solution.canMeasureWater(x, y, target);
    }
    
    return 0;
}