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

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j])
                    ans += 
                        (i == 0 || !grid[i - 1][j]) + 
                        (j == 0 || !grid[i][j - 1]) +
                        (i == m - 1 || !grid[i + 1][j]) + 
                        (j == n - 1 || !grid[i][j + 1]);
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

        cout << solution.islandPerimeter(grid) << endl;
    }
    
    return 0;
}