#include <iostream>
#include <vector>

using namespace std;

struct Point {
    short x, y;
    Point(short i, short j) {x = i, y = j;}
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if (board[i][j] == '.') unfixed.emplace_back(i, j);
        recursion(board, 0);
    }
private:
    vector<Point> unfixed;
    bool recursion(vector<vector<char>>& board, int i){
        if(i >= unfixed.size()) return true;
        int x = unfixed[i].x;
        int y = unfixed[i].y;

        for(char c = '1'; c <= '9'; c++){
            if(!valid(board, x, y, c)) continue;

            board[x][y] = c;
            if(recursion(board, i + 1)) return true;
        }

        board[x][y] = '.';
        return false;
    }
    bool valid(vector<vector<char>>& board, int x, int y, char c){
        for(int i = 0; i < 9; i++)
            if(board[i][y] == c) return false;
        for(int i = 0; i < 9; i++)
            if(board[x][i] == c) return false;
        x = x / 3 * 3;
        y = y / 3 * 3;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(board[x + i][y + j] == c) return false;
        return true;
    }
};

vector<char> parse_(string s){
    vector<char> v;
    int last = 1;
    for(int i = 1; i < s.length(); i++)
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
    //cout << "[";
    for(int i = 0; i < v.size(); i++){
        //cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout << "\"" << v[i][j] << "\"";
            if(j != v[i].size() - 1) cout << ",";    
        }
        //cout << "]";
        if(i != v.size() - 1) cout << endl; // ",";
    }
    //cout << "]";
    cout << endl;
}

int main() {
    Solution solution;

    while(true) {
        string s;
        cout << "board = ";
        cin >> s;
        vector<vector<char>> board = parse(s);
        
        cout << "board:" << endl;
        print(board);
        solution.solveSudoku(board);
        cout << "ans:" << endl;
        print(board);
    }
    
    return 0;
}