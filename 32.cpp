#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int len = s.length(), left = 0;
        for(int i = 0; i < len; i++) 
            if(s[i] == '(') stk.push(i), left++;
            else if(left > 0) stk.pop(), left--;
            else stk.push(i);

        int ans = 0;
        int last = len;
        while(!stk.empty())
            ans = max(ans, last - (last = stk.top()) - 1), stk.pop();
        ans = max(ans, last);
        return ans;
    }
/* Optimized Solution(maybe)
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int len = s.length();
        int ans = 0;
        for(int i = 0; i < len; i++) 
            if(s[i] == '(') stk.push(i);
            else {
                stk.pop();
                if(stk.empty()) stk.push(i);
                else ans = max(ans, i - stk.top());
            }
        return ans;
    }
*/
};

int main()
{
    Solution solution;

    while(true) {
        string s;
        cout << "s = ";
        cin >> s;

        cout << solution.longestValidParentheses(s) << endl;
    }
    
    return 0;
}