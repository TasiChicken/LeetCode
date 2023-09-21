#include <iostream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length(), len2 = version2.length(), i1 = 0, i2 = 0, n1, n2;
        
        while(i1 < len1 || i2 < len2){
            n1 = n2 = 0;
            for(; i1 < len1; i1++)
                if(version1[i1] == '.') break;
                else n1 = n1 * 10 - '0' + version1[i1];
            for(; i2 < len2; i2++)
                if(version2[i2] == '.') break;
                else n2 = n2 * 10 - '0' + version2[i2];
            if(n1 > n2) return 1;
            if(n1 < n2) return -1;
            i1++, i2++;
        }
        return 0;
    }
};

int main() {
    while(true) {
        Solution solution;
        string version1, version2;
        cout << "version1 = ";
        cin >> version1;
        cout << "version2 = ";
        cin >> version2;

        cout << solution.compareVersion(version1, version2) << endl;;
    }
    
    return 0;
}