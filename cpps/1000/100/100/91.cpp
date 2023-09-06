#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.length();
        int com = 0, ucom = 1;
        
        for(int i = 1; i < n; i++)
            if(s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') 
                if(s[i] == '0') com = ucom, ucom = 0;
                else ucom += com, com = ucom - com;
            else if(s[i] == '0') return 0;
            else ucom += com, com = 0;
        
        return com + ucom;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        
        cout << solution.numDecodings(s) << endl;
    }
    
    return 0;
}