#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(!x || x == 1) return x;
        if(x == -1) return (n & 1) == 0 ? 1 : -1;
        if(n == 0) return 1;
        if(n == INT_MIN) x *= x, n /= 2;
        if(n < 0) x = 1 / x, n = -n;
        return power(x, n);
    }
private:
    double power(double x, int n){
        if(n == 1) return x;
        double p = myPow(x, n >> 1);
        return p * p * (n % 2 ? x : 1);
    }
};

int main() {
    while(true) {
        Solution solution;
        double x;
        cout << "x = ";
        cin >> x;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.myPow(x, n);
    }
    
    return 0;
}