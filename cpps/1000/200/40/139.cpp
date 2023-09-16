#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> parse(string s){
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
    bool match(string &s, int len, int start, string& word){
        int l = word.length();
        if(start + l > len) return false;
        while(l)
            if(word[--l] != s[start + l]) return false;
        return true;
    }
    bool recursion(string& s, int len, int start, vector<string>& wordDict, unordered_map<int, bool>& mp){
        if(start >= len) return true;
        auto r = mp.find(start);
        if(r != mp.end()) return r->second;

        for(string w : wordDict)
            if(match(s, len, start, w) && recursion(s, len, start + w.length(), wordDict, mp))
                return mp[start] = true;
        return mp[start] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> mp;
        return recursion(s, s.length(), 0, wordDict, mp);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s, t;
        cout << "s = ";
        cin >> s;
        cout << "wordDict = ";
        cin >> t;
        auto wordDict = parse(t);

        cout << solution.wordBreak(s, wordDict) << endl;
    }
    
    return 0;
}