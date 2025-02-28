#include <bits/stdc++.h>

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
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(mat[i][j] == 0) visited[i][j] = true;
                else if(i > 0 && mat[i - 1][j] == 0 ||
                        i < m - 1 && mat[i + 1][j] == 0 ||
                        j > 0 && mat[i][j - 1] == 0 ||
                        j < n - 1 && mat[i][j + 1] == 0)
                        visited[i][j] = true, q.push({i, j});

        while(q.size()){
            for(int i = 0; i < 4; i++){
                auto temp = q.front();
                int& tar = i < 2 ? temp.first : temp.second;
                tar += i % 2 ? 1 : -1;

                if(tar < 0 || tar >= (i < 2 ? m : n)) continue;
                if(visited[temp.first][temp.second]) continue;

                mat[temp.first][temp.second] = 1 + mat[q.front().first][q.front().second];
                visited[temp.first][temp.second] = true;
                q.push(temp);
            }

            q.pop();
        }

        return mat;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "mat = ";
        cin >> s;
        auto mat = parse(s);

        print(solution.updateMatrix(mat));
    }
    
    return 0;
}