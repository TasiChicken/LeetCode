#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = min(x, 46340);
        while(left <= right){
            int mid = (left + right) / 2;
            if(mid * mid > x) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }
};

int main() {
    while(true) {
        Solution solution;
        int x;
        cout << "x = ";
        cin >> x;
        cout << solution.mySqrt(x) << endl;
    }
    
    return 0;
}