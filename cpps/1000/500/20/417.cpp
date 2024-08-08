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

void print(vector<vector<int>> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j];
            if(j != v[i].size() - 1) cout << ",";    
        }
        cout << "]";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    int direc[5] = {1, 0, -1, 0, 1}, m, n;
    vector<vector<int>> table;
    void recursion(vector<vector<int>>& h, int x, int y, int ocean){
        if(table[x][y] & ocean) return;
        table[x][y] |= ocean;

        for(int i = 0; i < 4; i++){
            int x1 = x + direc[i], y1 = y + direc[i + 1];
            if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && h[x][y] <= h[x1][y1])
                recursion(h, x1, y1, ocean);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        table = vector<vector<int>>(m, vector<int>(n));

        for(int i = 0; i < n; i++){
            recursion(heights, 0, i, 1);
            recursion(heights, m - 1, i, 2);
        }
        for(int i = 0; i < m; i++){
            recursion(heights, i, 0, 1);
            recursion(heights, i, n - 1, 2);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if((table[i][j] & 3) == 3)
                    ans.push_back({i, j});
        return ans; 
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout  << "heights = ";
        cin >> s;
        auto heights = parse(s);

        print(solution.pacificAtlantic(heights));
    }
    
    return 0;
}