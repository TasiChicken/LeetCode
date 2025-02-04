#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;

        int sum = 1;
        for(int i = 2; i * i <= num; i++)
            if(num % i == 0){
                if((sum += i) > num) return false;
                if(i * i != num) sum += num / i;
            }
        return sum == num;
    }
};

int main() {
    while(true) {
        Solution solution;
        int num;
        cout << "num = ";
        cin >> num;

        cout << solution.checkPerfectNumber(num) << endl;
    }
    
    return 0;
}