#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int table[9];

        for(int i = 0; i < 9; i++){
            fill(table, table + 9, 0);
            for(int j = 0; j < 9; j++){
                char c = board[i][j];

                if(c == '.') continue;
                int& num = table[c - '1'];
                if(num != 0) return false;
                else num++;
            }
        }

        for(int i = 0; i < 9; i++){
            fill(table, table + 9, 0);
            for(int j = 0; j < 9; j++){
                char c = board[j][i];
                
                if(c == '.') continue;
                int& num = table[c - '1'];
                if(num != 0) return false;
                else num++;
            }
        }
                

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++){
                fill(table, table + 9, 0);
                for(int k = 0; k < 3; k++)
                    for(int l = 0; l < 3; l++){
                        char c = board[i * 3 + k][j * 3 + l];
                        
                        if(c == '.') continue;
                        int& num = table[c - '1'];
                        if(num != 0) return false;
                        else num++;
                    }
            }

        return true;
    }
};

vector<char> parse_row(string input){
    vector<char> row;
    input.erase(input.length() - 1, 1);
    input.erase(0, 1);

    if(input.length() == 0) return row;

    int index = 0;
    for(int i = 0; i <= input.length(); i++) 
        if(input[i] == ',' || i == input.length()) {
            row.push_back(input[index + 1]);
            index = i + 1;
        }

    return row;
}

vector<vector<char>> parse_input(string input) {
    vector<vector<char>> board;
    input.erase(input.length() - 1, 1);
    input.erase(0, 1);

    if(input.length() == 0) return board;

    int index = 0;
    bool in_row = false;
    for(int i = 0; i <= input.length(); i++) 
        if (input[i] == '[') in_row = true;
        else if (input[i] == ']') in_row = false;
        else if (!in_row && (input[i] == ',' || i == input.length())) {
            board.push_back(parse_row(input.substr(index, i - index)));
            index = i + 1;
        }

    return board;
}

int main()
{
    Solution solution;

    while(true) {
        string input;
        cout << "board = ";
        cin >> input;
        vector<vector<char>> board = parse_input(input);

        cout << solution.isValidSudoku(board) << endl;
    }
    
    return 0;
}