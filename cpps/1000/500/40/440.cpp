#include <iostream>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 0;
        for(int i = 1; i < 10; i++){
            if(k == 1) return cur * 10 + i;
            int tempK = k;
            long long j = 1;
            while( (cur * 10 + i) * j <= n && j <= n)
                tempK -= min(n + 1 - (cur * 10 + i) * j, j), j *= 10;
            if(tempK <= 0)
                k--, cur = cur * 10 + i, i = -1;
            else k = tempK;
        }
        return -1;
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

        cout << solution.findKthNumber(n , k) << endl;
    }
    
    return 0;
}