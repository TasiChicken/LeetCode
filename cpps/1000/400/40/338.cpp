#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
public:    
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.reserve(n + 1);
        ans.push_back(0);
        for(int i = 1; i <= n; i++)
            ans.push_back(ans[i >> 1] + i % 2);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        print(solution.countBits(n));
    }
    
    return 0;
}