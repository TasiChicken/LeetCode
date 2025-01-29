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

void print(vector<string> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << '\"' << v[i] << '\"';
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    unordered_map<char, int> mp;
    bool check(string& word){
        for(auto word : word){}
        int num = mp[tolower(word[0])];
        for(int i = 1 ; i < word.size(); i++)
            if(mp[tolower(word[i])] != num)
                return false;
        return true;
    }
public:
    Solution () {
        string a = "qwertyuiop";
        string b = "asdfghjkl";
        string c = "zxcvbnm";
        for(char ch : a) mp[ch] = 0;
        for(char ch : b) mp[ch] = 1;
        for(char ch : c) mp[ch] = 2;
    }

    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for(auto& word : words)
            if(check(word)) ans.push_back(word);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "words = ";
        cin >> s;
        auto words = parse_(s);

        print(solution.findWords(words));
    }
    
    return 0;
}