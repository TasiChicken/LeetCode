#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int len1 = num1.length(), len2 = num2.length(), len = len1 + len2;
        string ans(len, 0);
        for(int i = len1 - 1; i >= 0; i--)
            for(int j = len2 - 1; j >= 0; j--){
                ans[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                if(ans[i + j + 1] < 10) continue;

                ans[i + j] += ans[i + j + 1] / 10;
                ans[i + j + 1] %= 10;
            }

        int start = 0;
        for(int i = 0; i < len; i++)
            if (start == i && ans[i] == 0) start++;
            else ans[i] += '0';
        return ans.substr(start);
    }
};

int main() {
    while(true) {
        Solution solution;
        string num1, num2;
        cout << "num1 = ";
        cin >> num1;
        cout << "num2 = ";
        cin >> num2;

        cout << solution.multiply(num1, num2) << endl;
    }
    
    return 0;
}