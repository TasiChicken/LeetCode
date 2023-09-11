#include <iostream>
#include <vector>

using namespace std;

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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.reserve(numRows);
        ans.push_back(vector<int>(1, 1));
        for(int i = 1; i < numRows; i++){
            ans.push_back(vector<int>());
            vector<int>& v = ans[i];
            v.reserve(i + 1);
            v.push_back(1);
            for(int j = 1; j < i; j++) v.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
            v.push_back(1);
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int numRows;
        cout << "numRows = ";
        cin >> numRows;

        print(solution.generate(numRows));
    }
    
    return 0;
}