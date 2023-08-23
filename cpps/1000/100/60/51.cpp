#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        this->n = n;
        recursion();
        return ans;
    }
private:
    vector<vector<string>> ans;
    vector<string> board;
    int n, x = 0, slash = 0, backslash = 0;
    void recursion(const int index = 0){
        if(index == n) return ans.push_back(board);

        for(int i = 0; i < n; i++){
            int x = 1 << i, slash = 1 << i + index, backslash = 1 << i - index + n;
            if(this->x & x || this->slash & slash || this->backslash & backslash) continue;

            this->x |= x, this->slash |= slash, this->backslash |= backslash;
            board[index][i] = 'Q';
            recursion(index + 1);
            board[index][i] = '.';
            this->x ^= x, this->slash ^= slash, this->backslash ^= backslash;
        }
    }
};

void print(vector<vector<string>> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout << "\"" << v[i][j] << "\"";
            if(j != v[i].size() - 1) cout << ",";    
        }
        cout << "]";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

int main() {
    while(true) {
        Solution solution;
        
        int n ;
        cout << "n = ";
        cin >> n;
        print(solution.solveNQueens(n));
    }
    
    return 0;
}