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

class Solution {
    bool isS(const string& a, const string& b){
        for(int i = 0, j = 0; j < b.size(); i++, j++){
            while(a[i] != b[j])
                if(a.size() - ++i < b.size() - j) 
                    return false;
        }
        return true;
    }
    map<int, unordered_map<string, int>> mp;
    bool isLUS(const string& s){
        for(auto it = mp.rbegin(); it != mp.rend() && it->first > s.size(); it++)
            for(auto& si : it->second)
                if(isS(si.first, s))
                 return false;
        return true;
    }
public:
    int findLUSlength(vector<string>& strs) {
        mp.clear();
        for(auto& s : strs)
            mp[s.size()][s]++;

        for(auto it = mp.rbegin(); it != mp.rend(); it++)
            for(auto& si : it->second)
                if(si.second == 1 && isLUS(si.first))
                    return it->first;
        return -1;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "strs = ";
        cin >> s;
        auto strs = parse_(s);

        cout << solution.findLUSlength(strs) << endl;
    }
    
    return 0;
}