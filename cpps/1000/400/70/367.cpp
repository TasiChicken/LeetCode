#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long i = 2; i * i <= num; i++)
            while(num % i == 0){
                if(num % (i * i)) return false;
                num /= i * i;
            }
        return num == 1;
    }
};

int main() {
    while(true) {
        Solution solution;
        int num;
        cout << "num = ";
        cin >> num;

        cout << solution.isPerfectSquare(num) << endl;
    }
    
    return 0;
}