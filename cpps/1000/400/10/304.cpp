#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
    vector<vector<int>> sums;
    int get_sum(int row, int col){
        if(row < 0 || col < 0) return 0;
        cout << sums[row][col];
        return sums[row][col];
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sums = matrix;

        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                sums[i][j] += get_sum(i - 1, j) + get_sum(i, j - 1) - get_sum(i - 1, j - 1);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return get_sum(row2, col2) - get_sum(row1 - 1, col2) - get_sum(row2, col1 - 1) + get_sum(row1 - 1, col1 - 1);
    }
};