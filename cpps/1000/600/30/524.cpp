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
    bool isS(string& a, string& b){
        for(int i = 0, j = 0; j < b.size(); i++, j++){
            while(i < a.size() && a[i] != b[j]) i++;
            if(a.size() - i < b.size() - j) return false;
        }
        return true;
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(auto& d : dictionary)
            if((d.size() > ans.size() || d.size() == ans.size() && d < ans) && isS(s, d))
                ans = d;
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        s = s.substr(1, s.size() - 2);
        string ds;
        cout << "dictionary = ";
        cin >> ds;
        auto dictionary = parse_(ds);

        cout << solution.findLongestWord(s, dictionary) << endl;
    }
    
    return 0;
}