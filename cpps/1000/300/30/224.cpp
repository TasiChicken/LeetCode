#include <iostream>
#include <stack>

using namespace std;

class Solution {
    int recursion(string& s, int& size, int& i){
        int num = 0, op = 1, num_begin = i, is_sign = true;
        for(; i < size && s[i] != ')'; i++)
            if(s[i] == '('){
                num += op * recursion(s, size, ++i);
                op = 0;
            }
            else if(s[i] == '+' || s[i] == '-'){
                if(!is_sign && op) num += op * stoi(s.substr(num_begin, i - num_begin));
                num_begin = i + 1;
                op = s[i] == '+' ? 1 : -1;
            }
            else if(is_sign && s[i] >= '0' && s[i] <= '9') is_sign = false;
        if(op) num += op * stoi(s.substr(num_begin, i - num_begin));
        return num;
    }
public:
    int calculate(string s) {
        int size = s.size(), i = 0;
        return recursion(s, size, i);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        getline(cin, s);
        cout << solution.calculate(s) << endl;
    }
    
    return 0;
}