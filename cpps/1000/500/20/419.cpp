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

class Solution {
    int dire[5] = {-1, 0, 1, 0, -1};
    void erase(vector<vector<char>>& board, int x, int y){
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'X')
            return;
        board[x][y] = '.';
        for(int i = 0; i < 4; i++)
            erase(board, x + dire[i], y + dire[i + 1]);
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(board[i][j] == 'X'){
                    ans++;
                    erase(board, i, j);
                }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "board = ";
        cin >> s;
        auto board = parse(s);

        cout << solution.countBattleships(board) << endl;
    }
    
    return 0;
}