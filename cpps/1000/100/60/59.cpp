#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(const int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int p[2] {0, 0}, layer, dir;
        for(int i = dir = layer = 0; i < n * n; i++){
            cout << "x = " << p[0] << "\ty = " << p[1] << endl;
            ans[p[1]][p[0]] = i + 1;

            if(p[dir & 1] + (dir >> 1 ? -1 : 1) == (dir >> 1 ? layer - 1 : n - layer)) 
                dir = dir + 1 & 3, layer += dir == 3;
            p[dir & 1] += dir >> 1 ? -1 : 1;
        }
        return ans;
    }
};

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
        int n;
        cout << "n = ";
        cin >> n;
        print(solution.generateMatrix(n));
    }
    
    return 0;
}