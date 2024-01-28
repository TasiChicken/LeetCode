#include <iostream>
#include <vector>

using namespace std;

vector<int> parse_(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}

vector<vector<int>> parse(string s){
    vector<vector<int>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
    return v;
}

void print(vector<vector<int>> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j];
            if(j != v[i].size() - 1) cout << ",";    
        }
        cout << "]";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    bool live(vector<vector<int>>& board, int m, int n, int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n && abs(board[x][y]) == 1;
    }
    void new_state(vector<vector<int>>& board, int m, int n, int x, int y){
        int alive_neighbors = 0;
        for(int dx = -1; dx <= 1; dx++)
            for(int dy = -1; dy <= 1; dy++)
                if(dx || dy) alive_neighbors += live(board, m, n, x + dx, y + dy);

        if(board[x][y] && (alive_neighbors < 2 || alive_neighbors > 3)) board[x][y] = -1;
        else if(!board[x][y] && alive_neighbors == 3) board[x][y] = -2;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                new_state(board, m, n, i, j);
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == -1) board[i][j] = 0;
                else if(board[i][j] == -2) board[i][j] = 1;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "board = ";
        cin >> s;
        auto board = parse(s);
        solution.gameOfLife(board);

        print(board);
    }
    
    return 0;
}