#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int i = 12;
        string ans = "";
        while(num != 0){
            while(num / values[i] > 0)
                ans += romans[i], num -= values[i];
            i--;
        }
        return ans;
    }
private:
    const string romans[13] = {"I","IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    const int values[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
};

int main()
{
    Solution solution;

    while(true) {
        int num;
        cout << "num = ";
        cin >> num;
        cout << solution.intToRoman(num) << endl;
    }
    
    return 0;
}