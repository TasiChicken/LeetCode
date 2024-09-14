#include <iostream>

using namespace std;

class Solution {
    int mp[1 << 21];
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal, int k = 0) {
        if(mp[k]) return mp[k] == 1;
        if(desiredTotal <= 0) return mp[k] = 1;
        if((maxChoosableInteger * maxChoosableInteger + maxChoosableInteger >> 1) < desiredTotal) return false;

        for(int i = 0; i < maxChoosableInteger; i++)
            if(!(k & (1 << i)) && (desiredTotal <= i + 1 || !canIWin(maxChoosableInteger, desiredTotal - i - 1, k | (1 << i))))
                return mp[k] = 1;
        mp[k] = -1;
        return false;
    }
};

int main() {
    while(true) {
        Solution solution;
        int maxChoosableInteger;
        cout << "maxChoosableInteger = ";
        cin >> maxChoosableInteger;
        int desiredTotal;
        cout << "desiredTotal = ";
        cin >> desiredTotal;

        cout << solution.canIWin(maxChoosableInteger, desiredTotal) << endl;
    }
    
    return 0;
}