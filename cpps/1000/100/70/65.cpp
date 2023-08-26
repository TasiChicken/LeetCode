#include <iostream>

using namespace std;

class Solution {
    bool isInteger(string s){
        bool number = false;
        for(int i = s[0] == '+' || s[0] == '-' ? 1 : 0; i < s.length(); i++)
            if(s[i] < '0' || s[i] > '9') return false;
            else number = true;
        return number;
    }
public:
    bool isNumber(string s) {
        bool number = false, dot = false;
        for(int i = s[0] == '+' || s[0] == '-' ? 1 : 0; i < s.length(); i++)
            if(s[i] >= '0' && s[i] <= '9') number = true;
            else if(s[i] == '.'){
                if(dot) return false;
                else dot = true;
            }
            else if(s[i] == 'E' || s[i] == 'e') return number && isInteger(s.substr(i + 1));
            else return false;
        return number;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;

        cout << solution.isNumber(s) << endl;
    }
    
    return 0;
}