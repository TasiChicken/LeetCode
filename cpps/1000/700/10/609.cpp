#include <bits/stdc++.h>

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

void print(vector<vector<string>> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout << '\"' << v[i][j] << '\"';
            if(j != v[i].size() - 1) cout << ",";    
        }
        cout << "]";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;

        for(auto p : paths){
            int idx = p.find(' ');
            string prefix = p.substr(0, idx);

            while (idx != -1){
                idx++;
                int l = p.find('(', idx), r = p.find(')', l + 1);
                mp[p.substr(l + 1, r - l - 1)].push_back(prefix + "/" + p.substr(idx, l - idx));
                idx = p.find(' ', idx);
            }
        }

        vector<vector<string>> ans;
        for(auto f : mp){
            if(f.second.size() > 1)
                ans.push_back(f.second);
        }

        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        getline(cin, s);
        auto paths = parse_(s);

        print(solution.findDuplicate(paths));
    }
    
    return 0;
}