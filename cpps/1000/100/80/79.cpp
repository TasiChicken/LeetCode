#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool recursion(vector<vector<char>>& board, string& word, int& len, int& m, int& n, int i, int j, int index = 0){
        if(index >= len) return true;
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) return false;

        board[i][j] = 0;
        if (
            recursion(board, word, len, m, n, i - 1, j, index + 1) ||
            recursion(board, word, len, m, n, i + 1, j, index + 1) ||
            recursion(board, word, len, m, n, i, j - 1, index + 1) ||
            recursion(board, word, len, m, n, i, j + 1, index + 1) 
        ) return true;
        board[i][j] = word[index];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), len = word.length();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(recursion(board, word, len, m, n, i, j))
                    return true;
        return false;
    }
};

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

vector<vector<char>> parse(string s){
    vector<vector<char>> v;
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
        cout << "board = ";
        cin >> s;
        auto board = parse(s);
        string word;
        cout << "word = ";
        cin >> word;

        cout << solution.exist(board, word) << endl;
    }
    
    return 0;
}