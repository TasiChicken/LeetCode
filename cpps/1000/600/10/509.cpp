#include <bits/stdc++.h>

using namespace std;

class Solution {
    void pow(vector<int>& res, int x){
        if(x == 1) return;

        pow(res, x >> 1);

        auto temp = res;
        res[0] = temp[0] * temp[0] + temp[1] * temp[2];
        res[1] = temp[0] * temp[1] + temp[1] * temp[3];
        res[2] = temp[2] * temp[0] + temp[3] * temp[2];
        res[3] = temp[2] * temp[1] + temp[3] * temp[3];

        if(x & 1){
            temp = res;
            res[0] = temp[0] + temp[1];
            res[1] = temp[0];
            res[2] = temp[2] + temp[3];
            res[3] = temp[2];
        }
    }
public:
    int fib(int n) {
        if(n < 3) return n != 0;

        vector<int> res = {1, 1, 1, 0};
        pow(res, n - 1);
        return res[0];
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.fib(n) << endl;
    }
    
    return 0;
}