#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<unsigned long long, int> mp;
        for(auto& level : wall){
            unsigned long long pos = 0;

            for(int i = 0; i < level.size() - 1; i++)
                mp[pos += level[i]]++;
        }

        int m = 0;
        for(auto it = mp.begin(); it != mp.end(); it++)
            m = max(m, it->second);

        return wall.size() - m;
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
        auto wall = parse(s);

        cout << solution.leastBricks(wall) << endl;
    }
    
    return 0;
}