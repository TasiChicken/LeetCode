#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for(auto & op : ops)
            m = min(m, op[0]), n = min(n, op[1]);
        return m * n;
    }
};

vector<int> parse_(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}

vector<vector<int>> parse(string s){
    vector<vector<int>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
    return v;
}

int main() {
    while(true) {
        Solution solution;
        int m, n;
        string s;
        cin >> m >> n >> s;
        auto ops = parse(s);

        cout << solution.maxCount(m, n, ops) << endl;
    }
    
    return 0;
}