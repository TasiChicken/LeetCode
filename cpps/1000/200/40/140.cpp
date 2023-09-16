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

void print(vector<string> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << '\'' << v[i] << '\'';
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    bool match(string &s, int len, int start, string& word){
        int l = word.length();
        if(start + l > len) return false;
        while(l)
            if(word[--l] != s[start + l]) return false;
        return true;
    }
    vector<string> recursion(string& s, int len, int start, vector<string>& wordDict, unordered_map<int, vector<string>>& mp){
        if(start >= len) return vector<string>();
        auto r = mp.find(start);
        if(r != mp.end()) return r->second;

        for(string w : wordDict)
            if(match(s, len, start, w)){
                int nextS = start + w.length();
                
                if(nextS >= len) mp[start].push_back(w);
                else
                    for(string str : recursion(s, len, nextS, wordDict, mp))
                        mp[start].push_back(w + ' ' + str);
            }
        return mp[start];
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, vector<string>> mp;
        return recursion(s, s.length(), 0, wordDict, mp);
    }
/*Optimized Solution
    bool match(string &s, int len, int start, string& word){
        int l = word.length();
        if(start + l > len) return false;
        while(l)
            if(word[--l] != s[start + l]) return false;
        return true;
    }
    void recursion(string& s, int len, int start, vector<string>& wordDict, string& temp, vector<string>& ans){
        for(string w : wordDict)
            if(match(s, len, start, w))
                if(w.length() + start >= len) ans.push_back(temp + w);
                else{
                    temp += w + ' ';
                    recursion(s, len, start + w.length(), wordDict, temp, ans);
                    for(int i = 0; i <= w.length(); i++)
                        temp.pop_back();
                }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string temp;
        recursion(s, s.length(), 0, wordDict, temp, ans);
        return ans;
    }
*/
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

        print(solution.wordBreak(s, wordDict));
    }
    
    return 0;
}