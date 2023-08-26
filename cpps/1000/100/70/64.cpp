#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j;
        for(i = 1; i < m; i++)
            grid[i][0] += grid[i - 1][0];
        for(j = 1; j < n; j++)
            grid[0][j] += grid[0][j - 1];
        for(i = 1; i < m; i++)
            for(j = 1; j < n; j++)
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        return grid[m - 1][n - 1];
    }
};

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

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "grid = ";
        cin >> s;
        auto grid = parse(s);

        cout << solution.minPathSum(grid) << endl;
    }
    
    return 0;
}