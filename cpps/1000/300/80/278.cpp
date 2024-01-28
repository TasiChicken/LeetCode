#include <iostream>

using namespace std;

bool isBadVersion(int version);
int bad_ver;

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, m;
        while(l <= r){
            m = l + (r - l >> 1);
            if(isBadVersion(m)) r = m - 1;
            else l = m + 1;
        }
        return r + 1;
    }
};

bool isBadVersion(int version){
    return version >= bad_ver;
}

int main() {
    while(true) {
        Solution solution;
        int n, bad;
        cout << "n = ";
        cin >> n;
        cout << "bad = ";
        cin >> bad;
        bad_ver = bad;

        cout << solution.firstBadVersion(n) << endl;
    }
    
    return 0;
}