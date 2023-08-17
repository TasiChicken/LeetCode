#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s)
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else if(st.empty()) return false;
            else{
                if(abs(c - st.top()) > 2) return false;
                st.pop();
            }
        return st.empty();
    }
};

int main()
{
    Solution solution;

    while(true) {
        string s;
        cout << "s = ";
        cin >> s;
        cout << solution.isValid(s) << endl;
    }
    
    return 0;
}