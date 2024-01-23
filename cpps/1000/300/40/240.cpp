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
    bool searchMatrix(vector<vector<int>>& matrix, int target, int l, int r, int t, int b){
        if(l > r || t > b) return false;

        int x = l + r >> 1, y = t + b >> 1;
        if(matrix[y][x] == target) return true;
        if(matrix[y][x] > target) return 
            searchMatrix(matrix, target, l, x - 1, t, y - 1) ||
            searchMatrix(matrix, target, x, r, t, y - 1) ||
            searchMatrix(matrix, target, l, x - 1, y, b);
        return 
            searchMatrix(matrix, target, x + 1, r, y + 1, b) ||
            searchMatrix(matrix, target, x + 1, r, t, y) ||
            searchMatrix(matrix, target, l, x, y + 1, b);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix(matrix, target, 0, matrix[0].size() - 1, 0, matrix.size() - 1);
    }
/*Optimized Solution
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0, m = matrix[0].size() - 1, y = matrix.size() - 1;
        while(x <= m && y >= 0){
            if(matrix[y][x] == target) return true;
            if(matrix[y][x] < target) x++;
            else y--;
        }
        return false;
    }
*/
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "matrix = ";
        cin >> s;
        auto matrix = parse(s);
        int target;
        cin >> target;

        cout << solution.searchMatrix(matrix, target) << endl;
    }
    
    return 0;
}