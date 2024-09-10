#include <iostream>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = minutesToTest / minutesToDie + 1;
        for(int i = 0, num = 1; ; i++, num *= base)
            if(num >= buckets) return i;
    }
};

int main() {
    while (true){
        Solution solution;
        
        int buckets, minutesToDie, minutesToTest;

        // Prompt for each input
        cout << "buckets = ";
        cin >> buckets;

        cout << "minutesToDie = ";
        cin >> minutesToDie;

        cout << "minutesToTest = ";
        cin >> minutesToTest;

        // Call the function and output only the return value
        cout << solution.poorPigs(buckets, minutesToDie, minutesToTest) << endl;
    }

    return 0;
}
