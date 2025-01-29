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

void print(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int y = 0, x = 0, inc_y = -1, inc_x = 1, next_d_y = 0, next_d_x = 1;
        vector<int> ans;

        while(y < m && x < n){
            ans.push_back(mat[y][x]);
            y += inc_y, x += inc_x;
            if(y >= 0 && y < m && x >= 0 && x < n) continue;
                
            y -= inc_y, x -= inc_x;
            swap(inc_y, inc_x);

            y += next_d_y, x += next_d_x;
            swap(next_d_y, next_d_x);
            if(y >= 0 && y < m && x >= 0 && x < n) continue;

            y += next_d_y - next_d_x, x += next_d_x - next_d_y;
        }

        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "mat = ";
        cin >> s;
        auto mat = parse(s);

        print(solution.findDiagonalOrder(mat));
    }
    
    return 0;
}