#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void dfs(vector<vector<int>>& ans, vector<int>& mp, int min, int n, int k){
        if(k == 0 && n == 0) ans.push_back(mp);
        if(k <= 0 || n <= 0) return;

        for(int i = min; i <= 9; i++){
            mp.push_back(i);
            dfs(ans, mp, i + 1, n - i, k - 1);
            mp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> mp;
        dfs(ans, mp, 1, n, k);
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
        int k, n;
        cout << "k = ";
        cin >> k;
        cout << "n = ";
        cin >> n;

        print(solution.combinationSum3(k, n));
    }
    
    return 0;
}