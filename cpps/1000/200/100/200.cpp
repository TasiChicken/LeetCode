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
    void over(vector<vector<char>>& grid, int m, int n, int x, int y){
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1') return;
        grid[x][y] = '0';
        over(grid, m, n, x - 1, y);
        over(grid, m, n, x + 1, y);
        over(grid, m, n, x, y - 1);
        over(grid, m, n, x, y + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == '1') ans++, over(grid, m, n, i, j);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "grid = ";
        cin >> s;
        auto grid = parse(s);

        cout << solution.numIslands(grid) << endl;
    }
    
    return 0;
}