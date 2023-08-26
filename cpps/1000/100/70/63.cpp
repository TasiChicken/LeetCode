#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size(), i, j;
        if(obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;

        for(i = 0 ; i < m; i++)
            if(obstacleGrid[i][0]) 
                while(i < m) obstacleGrid[i++][0] = 0;
            else obstacleGrid[i][0] = 1;
        for(j = 1 ; j < n; j++)
            if(obstacleGrid[0][j]) 
                while(j < n) obstacleGrid[0][j++] = 0;
            else obstacleGrid[0][j] = 1;

        for(i = 1 ; i < m; i++)
            for(j = 1 ; j < n; j++)
                obstacleGrid[i][j] = obstacleGrid[i][j] ? 0 : obstacleGrid[i - 1][j] +  obstacleGrid[i][j - 1];
        return obstacleGrid[m - 1][n - 1];
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
        cout << "obstacleGrid = ";
        cin >> s;
        auto obstacleGrid = parse(s);

        cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
    }
    
    return 0;
}