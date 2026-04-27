#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
    void compute(ll &num, ll &den, ll cnum, ll cden){
        ll g = gcd(den, cden);
        num = num * cden / g + cnum * den / g;
        den *= cden / g;

        g = gcd(num, den);
        num /= g;
        den /= g;
    }
public:
    string fractionAddition(string expression) {
        ll num = 0, den = 1;

        int prev = 0;
        ll cur_num;
        for(int i = 1; i < expression.size(); i++)
            if(expression[i] == '/'){
                cur_num = stoll(expression.substr(prev, i - prev));
                prev = ++i;
            }
            else if(expression[i] == '+' ||expression[i] == '-'){
                compute(num, den, cur_num, stoll(expression.substr(prev, i - prev)));
                prev = i;
            }

        compute(num, den, cur_num, stoll(expression.substr(prev)));
        return to_string(num) + "/" + to_string(den);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        s = s.substr(1, s.size() - 2);

        cout << solution.fractionAddition(s) << endl;
    }
    
    return 0;
}