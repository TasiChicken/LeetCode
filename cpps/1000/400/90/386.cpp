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

using namespace std;

class Solution {
    void add_num(vector<int>& nums, int num, int n){
        nums.push_back(num);

        num *= 10;
        if(num > n) return;
        for(int i = 0; i < 10 && num + i <= n; i++)
            add_num(nums, num + i, n);
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i < 10 && i <= n; i++)
            add_num(ans, i, n);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        print(solution.lexicalOrder(n));
    }
    
    return 0;
}