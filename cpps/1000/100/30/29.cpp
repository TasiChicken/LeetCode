#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == INT_MIN) return dividend == INT_MIN;
        if(divisor == 1) return dividend;
        if(divisor == -1) return dividend == INT_MIN ? INT_MAX : -dividend;

        bool negative = dividend < 0 ^ divisor < 0;
        bool tooBig = dividend == INT_MIN;
        dividend = tooBig ? INT_MAX : abs(dividend);
        divisor = abs(divisor);

        int ans = 0;

        while(dividend >= divisor) {
            int time = 0;
            while(INT_MAX >> 1 >= divisor << time && dividend > divisor << time + 1) time++;
            ans += (1 << time);
            dividend -= divisor << time;
        }

        ans += tooBig && dividend + 1 == divisor;
        return negative ? -ans : ans;
    }
};

int main()
{
    Solution solution;

    while(true) {
        int dividend, divisor;
        cout << "divdidend = ";
        cin >> dividend;
        cout << "divisor = ";
        cin >> divisor;

        cout << solution.divide(dividend, divisor) << endl;
    }
    
    return 0;
}