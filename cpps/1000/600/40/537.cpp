#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        pair<int, int>  n1, n2, ans;

        int p1 = distance(num1.begin(), find(num1.begin(), num1.end(), '+'));
        int p2 = distance(num2.begin(), find(num2.begin(), num2.end(), '+'));

        n1.first = stoi(num1.substr(0, p1));
        n1.second = stoi(num1.substr(p1 + 1, num1.size() - p1 - 2));;
        n2.first = stoi(num2.substr(0, p2));
        n2.second = stoi(num2.substr(p2 + 1, num2.size() - p2 - 2));;

        ans.first = n1.first * n2.first - n1.second * n2.second;
        ans.second = n1.first * n2.second + n2.first * n1.second;

        char buffer[20];
        sprintf(buffer, "%d+%di", ans.first, ans.second);
        return buffer;
    }
};

int main() {
    while(true) {
        Solution solution;
        string num1, num2;
        cout << "num1 = ";
        cin >> num1;
        num1 = num1.substr(1, num1.size() - 2);
        cout << "num2 = ";
        cin >> num2;
        num2 = num2.substr(1, num2.size() - 2);

        cout << solution.complexNumberMultiply(num1, num2) << endl;
    }
    
    return 0;
}