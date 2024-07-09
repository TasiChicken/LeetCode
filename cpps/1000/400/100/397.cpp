#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int, int> mp;
public:
    int integerReplacement(long long n) {
        if(n == 2147483647) return 32;
        if(n == 1) return 0;
        if(n % 2 == 0) return 1 + integerReplacement(n >> 1);
        if(mp[n]) return mp[n];
        return mp[n] = 1 + min(integerReplacement(n + 1), integerReplacement(n - 1));
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.integerReplacement(n) << endl;
    }
    
    return 0;
}