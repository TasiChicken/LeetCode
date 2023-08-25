#include <iostream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        ans.resize(n);
        int fac = 1; //n!
        for(int i = 0; i < n; fac *= ++i) ans[i] = '1' + i;

        k--;
        for(int i = 0; i < n; i++){
            fac /= n - i;
            for(int j = k / fac; j > 0;)
                swap(ans[i + j--], ans[i + j]);
            k %= fac;
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n, k;
        cout << "n = ";
        cin >> n;
        cout << "k = ";
        cin >> k;

        cout << solution.getPermutation(n, k) << endl;
    }
    
    return 0;
}