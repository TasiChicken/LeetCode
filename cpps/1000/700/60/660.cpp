#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for(int i = 0; i < m; i++)      
            for(int j = 0; j < n; j++){
                int num = 0, den = 0;

                for(int di = -1; di <= 1; di++)
                    for(int dj = -1; dj <= 1; dj++){
                        if(i + di >= m || i + di < 0 || j + dj >= n || j + dj < 0)
                            continue;

                        num += img[i + di][j + dj];
                        den++;
                    }

                res[i][j] = num / den;
            }
        return res;
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}