#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> col;
        for(int i = 0; i < m; i++){
            bool zero = false;
            for(int j = 0; j < n; j++){
                if(!matrix[i][j]){
                    if(!zero) 
                        for(int k = 0; k < j; k++)
                            matrix[i][k] = 0;
                    zero = true;
                    col.insert(j);
                }
                else if(zero) matrix[i][j] = 0;
            }
        }
        for(int c : col)
            for(int i = 0; i < m; i++)
                matrix[i][c] = 0;
    }
};

vector<int> parse(string s){
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
        else if(s[i] == ']') v.push_back(parse(s.substr(last, i - last + 1)));
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
        cout << "matrix = ";
        cin >> s;
        auto matrix = parse(s);
        solution.setZeroes(matrix);
        
        print(matrix);
    }
    
    return 0;
}