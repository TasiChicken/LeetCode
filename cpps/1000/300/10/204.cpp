#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int ans = n > 2;
        if(!ans) return 0;

        n = n - 2 >> 1;
        bool* p = new bool[n];
        for(int i = 0; i < n; i++)
            p[i] = true;

        for(int i = 0; i < n; i++)
            if(p[i]){
                ans++;
                for(int j = i; j < n; j += i * 2 + 3)
                    p[j] = false;
            }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.countPrimes(n) << endl;
    }
    
    return 0;
}