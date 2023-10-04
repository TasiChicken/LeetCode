#include <iostream>
#include <vector>

using namespace std;

vector<char> parse_(string s){
    vector<char> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(s[last + 1]);
            last = i + 1;
        }
    return v;
}

vector<vector<char>> parseB(string s){
    vector<vector<char>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
    return v;
}

vector<string> parseW(string s){
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

class WordDictionary {   
    void addWord(string &word, int start){
        if(start == word.length()){
            end = true;
            return;
        } 

        int index = word[start] - 'a';
        if(!dic[index]) dic[index] = new WordDictionary();
        dic[index]->addWord(word, start + 1);
    }

    bool search(string& word, int start){
        if(start == word.length()) return end;
        if(word[start] != '.'){
            int index = word[start] - 'a';
            return dic[index] && dic[index]->search(word, start + 1);
        }

        for(int index = 0; index < 26; index++)
            if(dic[index] && dic[index]->search(word, start + 1))
                return true;
        return false;
    }
public:
    WordDictionary* dic[26];
    bool end = false;

    WordDictionary() {
        for(int i = 0; i < 26; i++) 
            dic[i] = nullptr;
    }

    void addWord(string word) {
        addWord(word, 0);
    }
    
    bool search(string word) {
        return search(word, 0);
    }
};

class Solution {
    void findMatch(vector<vector<char>>& board, int x, int y, int m, int n, vector<string> &ans, string &s, WordDictionary* wd){
        if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == ' ' || !(wd = wd->dic[board[x][y] - 'a'])) return;

        s.push_back(board[x][y]);
        board[x][y] = ' ';
        if(wd->end){
            ans.push_back(s);
            wd->end = false;
        } 

        findMatch(board, x + 1, y, m, n, ans, s, wd);
        findMatch(board, x - 1, y, m, n, ans, s, wd);
        findMatch(board, x, y + 1, m, n, ans, s, wd);
        findMatch(board, x, y - 1, m, n, ans, s, wd);

        board[x][y] = s.back();
        s.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        WordDictionary wordDic;
        for(auto s : words) wordDic.addWord(s);

        int m = board.size(), n = board[0].size();
        string s;
        vector<string> ans;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                findMatch(board, i, j, m, n, ans, s, &wordDic);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "board = ";
        cin >> s;
        auto board = parseB(s);
        cout << "words = ";
        cin >> s;
        auto words = parseW(s);

        print(solution.findWords(board, words));
    }
    
    return 0;
}