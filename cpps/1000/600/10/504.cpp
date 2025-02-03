#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        bool neg;
        if(neg = num < 0) num = -num;

        string ans;
        do{
            ans.push_back(num % 7 + '0');
            num /= 7;
        } while(num);

        if(neg) ans.push_back('-');
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int num;
        cout << "num = ";
        cin >> num;

        cout << solution.convertToBase7(num) << endl;
    }
    
    return 0;
}