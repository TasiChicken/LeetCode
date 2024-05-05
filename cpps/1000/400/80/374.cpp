#include <iostream>

using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long l = 1;
        while(true){
            int mid = l + n >> 1;
            switch (guess(mid))
            {
            case 1:
                l = mid + 1;
                break;
            case -1:
                n = mid - 1;
                break;
            default:
                return mid;
            }
        }
    }
};

int pick;

int guess(int num){
    if(num > pick) return -1;
    if(num < pick) return 1;
    return 0;
}

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;
        cout << "pick = ";
        cin >> pick;

        cout << solution.guessNumber(pick) << endl;
    }
    
    return 0;
}