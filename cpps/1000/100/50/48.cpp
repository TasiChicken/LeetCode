#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), i, j;
        for(i = 1; i < n; i++)
            for(j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);

        for(i = 0; i < n; i++)
            for(j = 0; j < n / 2; j++)
                swap(matrix[i][j], matrix[i][n - 1 - j]);
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
            cout <<v[i][j];
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
        vector<vector<int>> matrix = parse(s);
        
        solution.rotate(matrix);
        print(matrix);
    }
    
    return 0;
}