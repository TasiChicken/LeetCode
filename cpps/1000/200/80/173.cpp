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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size() - 1, n = dungeon[0].size() - 1;
        dungeon[m][n] = max(1, -dungeon[m][n] + 1);

        for(int i = m - 1; i >= 0; i--) 
            dungeon[i][n] = max(1, dungeon[i + 1][n] - dungeon[i][n]);
        for(int j = n - 1; j >= 0; j--) 
            dungeon[m][j] = max(1, dungeon[m][j + 1] - dungeon[m][j]);
        for(int i = m - 1; i >= 0; i--) 
            for(int j = n - 1; j >= 0; j--) 
                dungeon[i][j] = max(1, min(dungeon[i + 1][j], dungeon[i][j + 1]) - dungeon[i][j]);
        return dungeon[0][0];
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "dungeon = ";
        cin >> s;
        auto dungeon = parse(s);

        cout << solution.calculateMinimumHP(dungeon) << endl;
    }
    
    return 0;
}