#include <iostream>

using namespace std;

class Solution {
public:
    int rand10() {
        int n = 41;
        while(n > 40)
            n = (rand7() - 1) * 7 + rand7();
        return n % 10 + 1;
    }
};