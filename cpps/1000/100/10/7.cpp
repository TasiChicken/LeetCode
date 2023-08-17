#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while(x != 0){
            if(x / 10 == 0 && (ans > INT_MAX / 10 || ans < INT_MIN / 10))
                return 0;

            ans *= 10;
            ans += x % 10;
            x /= 10;
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    while(true) {
        int x;
        cout << "x = ";
        cin >> x;

        cout << solution.reverse(x) << endl;
    }
    return 0;
}