#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

class Solution {
public:
    string smallestGoodBase(string n) {
        ull num = stoull(n);
        for(int i = log2(num + 1); i >= 2; i--){
            ull k = pow(num, 1.0 / (i - 1));
            while(true){
                ull sum = 1;
                for(int j = 1; j < i; j++)
                    sum = sum * k + 1;

                if(sum == num) return to_string(k);
                else if(sum < num) break;
                k--;
            }
        }

        return to_string(num - 1);
    }
};

int main() {
    while(true) {
        Solution solution;
        string n;
        cout << "n = ";
        cin >> n;

        cout << solution.smallestGoodBase(n) << endl;
    }
    
    return 0;
}