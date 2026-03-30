#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();

        if(m * n != r * c) return mat;

        vector<vector<int>> ans = vector<vector<int>>(r, vector<int>(c));
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++){
                int idx = i * r + j;
                ans[i][j] = mat[idx / n][idx % n];
            }
        
        return ans;
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

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        auto mat = parse(s);
        int r, c;
        cin >> r >> c;

        print(solution.matrixReshape(mat, r, c));
    }
    
    return 0;
}