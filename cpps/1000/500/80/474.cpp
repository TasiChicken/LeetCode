#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> parse_(string s){
    vector<string> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(s.substr(last + 1, i - last - 2));
            last = i + 1;
        }
    return v;
}

class Solution {
    int recursion(map<int, vector<int>>::iterator begin, map<int, vector<int>>::iterator end, int m, int n){
        if(begin == end) return 0;
        int cnt = 0, ans = 0;
        for(cnt = 0; cnt < begin->second.size() && m >= 0 && n >= 0; cnt++){
            m -= begin->second[cnt];
            n -= begin->first;
            if(m < 0 || n < 0) break;
        }

        for(; cnt >= 0; cnt--){
            if(cnt < begin->second.size()){
                m += begin->second[cnt];
                n += begin->first;
            }

            ans = max(ans, cnt + recursion(next(begin), end, m, n));
        }
        return ans;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        map<int, vector<int>> mp;
        for(auto& s : strs){
            int _0 = 0, _1 = 0;
            for(char& c : s)
                if(c == '0') _0++;
                else _1++;

            mp[_1].push_back(_0);
        }

        for(auto& m : mp)
            sort(m.second.begin(), m.second.end());

        return recursion(mp.begin(), mp.end(), m, n);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "str = ";
        cin >> s;
        auto str = parse_(s);
        int m, n;
        cout << "m = ";
        cin >> m;
        cout << "n = ";
        cin >> n;

        cout << solution.findMaxForm(str, m, n) << endl;
    }
    
    return 0;
}