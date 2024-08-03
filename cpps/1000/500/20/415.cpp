#include <iostream>

using namespace std;

class Solution {
public:
    string addStrings(string& num1, string& num2) {
        if(num1.size() < num2.size()) return addStrings(num2, num1);
        for(int i = 0; i < num1.size(); i++){
            if(i < num2.size())
                num1[num1.size() - i - 1] += num2[num2.size() - i - 1] - '0';
            else if(num1[num1.size() - i - 1] <= '9')
                break;
            if(num1[num1.size() - i - 1] > '9'){
                num1[num1.size() - i - 1] -= 10;
                if(num1.size() - i - 1)
                    num1[num1.size() - i - 2]++;
                else return "1" + num1;
            }
        }
        return num1;
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

        cout << solution.addStrings(num1, num2) << endl;
    }
    
    return 0;
}