#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;

        while (s[0] == ' ')
            s.erase(0, 1);

        bool isNegative = s[0] == '-';
        if(s[0] == '-' || s[0] == '+') s.erase(0, 1);

        int i = 0;
        while(s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + s[i] - '0';
            i++;
            
            if(!isNegative && ans > INT_MAX) return INT_MAX;
            else if(isNegative && -ans < INT_MIN) return INT_MIN;
        }

        return isNegative ? -ans : ans;
    }
};

int main()
{
    Solution solution;

    while(true) {
        string s;
        cout << "s = ";
        cin >> s;
        cout << solution.myAtoi(s) << endl;
    }
    
    return 0;
}