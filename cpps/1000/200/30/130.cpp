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

vector<vector<char>> parse(string s){
    vector<vector<char>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
    return v;
}

void print(vector<vector<char>> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout << '\'' << v[i][j] << '\'';
            if(j != v[i].size() - 1) cout << ",";    
        }
        cout << "]";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    void spread(vector<vector<char>>& board, int m, int n, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
        board[i][j] = '!';
        spread(board, m, n, i + 1, j);
        spread(board, m, n, i - 1, j);
        spread(board, m, n, i, j + 1);
        spread(board, m, n, i, j - 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        int  m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') spread(board, m, n, i, 0);
            if(board[i][n - 1] == 'O') spread(board, m, n, i, n - 1);
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O') spread(board, m, n, 0, j);
            if(board[m - 1][j] == 'O') spread(board, m, n, m - 1, j);
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == '!') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "board = ";
        cin >> s;
        auto board = parse(s);
        solution.solve(board);

        print(board);
    }
    
    return 0;
}