#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int* arr = new int[n + 1];
        arr[0] = arr[1] = 1;

        for(int i = 2, half = 1; i <= n; half = ++i >> 1){
            arr[i] = 0;
            for(int j = 0; j < half; j++)
                arr[i] += arr[j] * arr[i - j - 1];
            arr[i] <<= 1;
            if(i & 1) arr[i] += arr[half] * arr[half];
        }

        return arr[n];
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;
        
        cout << solution.numTrees(n) << endl;
    }
    
    return 0;
}