#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(!--m || !--n) return 1;
        if(m < n) swap(m, n);

        long ans = 1, div = 2;
        for(int i = m + n; i > m;){
            int mul = i--;
            while(div <= n && mul % div == 0) mul /= div++;
            ans *= mul;
            while(div <= n && ans % div == 0) ans /= div++;
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int m, n;
        cout << "m = ";
        cin >> m;
        cout << "n = ";
        cin >> n;

        cout << solution.uniquePaths(m, n) << endl;
    }
    
    return 0;
}