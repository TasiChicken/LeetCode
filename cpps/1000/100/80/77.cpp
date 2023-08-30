#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void recursion(vector<vector<int>>& ans, vector<int>& v, int n, int k, int num = 1){
        if(!k) return ans.push_back(v);

        for(int i = num; i <= n; i++){
            v.push_back(i);
            recursion(ans, v, n, k - 1, i + 1);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        v.reserve(k);
        recursion(ans, v, n, k);
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
        int n, k;
        cout << "n =";
        cin >> n;
        cout << "k =";
        cin >> k;

        print(solution.combine(n, k));
    }
    
    return 0;
}