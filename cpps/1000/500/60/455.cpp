#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = s.size() - 1, ans = 0;
        for(int i = g.size() - 1; i >= 0 && j >= 0; i--)
            if(s[j] >= g[i]) j--, ans++;
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string inp_s;
        cout << "g = ";
        cin >> inp_s;
        auto g = parse_(inp_s);
        cout << "s = ";
        cin >> inp_s;
        auto s = parse_(inp_s);

        cout << solution.findContentChildren(g, s) << endl;
    }
    
    return 0;
}