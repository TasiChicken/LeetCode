#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int l = arrays[0][0], u = arrays[0].back();
        int l_idx = 0, u_idx = 0;
        int l_2 = INT_MAX, u_2 = INT_MIN;

        for(int i = 1; i < arrays.size(); i++){
            if(arrays[i][0] <= l) l_2 = l, l_idx = i, l = arrays[i][0];
            else if(arrays[i][0] <= l_2) l_2 = arrays[i][0];
            if(arrays[i].back() >= u) u_2 = u, u_idx = i, u = arrays[i].back();
            else if(arrays[i].back() >= u_2) u_2 = arrays[i].back();
        }

        if(u_idx != l_idx) return u - l;

        return max(u - l_2, u_2 - l);
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
        string s;
        cin >> s;
        auto arr = parse(s);

        cout << solution.maxDistance(arr) << endl;
    }
    
    return 0;
}
