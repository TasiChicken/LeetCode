#include <bits/stdc++.h>

using namespace std;

class Solution {
    pair<int, int> parse(string s){
        int prev = 0;
        pair<int, int> res = {0, 0};
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'x'){
                if(i == prev || i - prev == 1 && (s[prev] < '0' || s[prev] > '9'))
                    res.first += (i == prev || s[prev] == '+') ? 1 : -1;
                else
                    res.first += stoi(s.substr(prev, i - prev));
                prev = i + 1;
                continue;
            }

            if(s[i] < '0' || s[i] > '9'){
                if(i > prev)
                    res.second += stoi(s.substr(prev, i - prev));
                prev = i;
            }

            if(i == s.size() - 1 && i >= prev)
                res.second += stoi(s.substr(prev));
        }
        return res;
    }
public:
    string solveEquation(string equation) {
        int spl = equation.find('=');
        auto l = parse(equation.substr(0, spl));
        auto r = parse(equation.substr(spl + 1));

        int x = l.first - r.first;
        int c = r.second - l.second;

        if(x == 0) return c == 0 ? "Infinite solutions" : "No solution";
        return "x=" + to_string(c / x);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        s = s.substr(1, s.size() - 1);

        cout << solution.solveEquation(s) << endl;
    }
    
    return 0;
}