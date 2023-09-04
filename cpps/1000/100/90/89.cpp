#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.reserve(1 << n);
        ans.push_back(0);
        
        int counter = 1;
        for(int i = 0; i < n; i++){
            for(int j = counter; j > 0; )
                ans.push_back(ans[--j] + counter);
            counter <<= 1;
        }
        return ans;
    }
};

void print(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
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
        
        print(solution.grayCode(n));
    }
    
    return 0;
}