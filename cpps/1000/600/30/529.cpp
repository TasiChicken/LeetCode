#include <bits/stdc++.h>

using namespace std;

vector<int> parse_i(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}

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
    void update(vector<vector<char>>& board, int y, int x){
        if(y < 0 || y >= board.size() || x < 0 || x >= board[0].size())
            return;
        if(board[y][x] == 'M') return;
        if(board[y][x] != 'E') return;
        
        if(y == 2 && x == 0)
            cout << "yes"<< endl;

        int cnt = 0;
        for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++)
                if(y + i >= 0 && y + i < board.size() && 
                x + j >= 0 && x + j < board[0].size() && 
                board[y + i][x + j] == 'M') cnt++;
        
        if(cnt){
            board[y][x] = '0' + cnt;
            return;
        } 

        board[y][x] = 'B';
        for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++)
                update(board, y + i, x + j);
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M')
            board[click[0]][click[1]] = 'X';
        else update(board, click[0], click[1]);
        return board;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "board = ";
        cin >> s;
        auto board = parse(s);
        cout << "click = ";
        cin >> s;
        auto click = parse_i(s);

        print(solution.updateBoard(board, click));
    }
    
    return 0;
}