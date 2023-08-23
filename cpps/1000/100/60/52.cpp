#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        this->n = n;
        recursion();
        return ans;
    }
private:
    vector<string> board;
    int n, x = 0, slash = 0, backslash = 0, ans = 0;
    void recursion(const int index = 0){
        if(index == n && ++ans) return;

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

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;
        cout << n << endl;
        cout << solution.totalNQueens(n) << endl;
    }
    
    return 0;
}