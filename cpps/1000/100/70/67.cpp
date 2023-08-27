#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = a.length(), lenB = b.length();
        if(lenA < lenB) swap(a, b), swap(lenA, lenB);
        for(int i = 1; i <= lenA; i++){
            if(i <= lenB) a[lenA - i] += b[lenB - i] - '0';
            else if(a[lenA - i] <= '1') break;

            if(a[lenA - i] > '1'){
                a[lenA - i] -= 2;
                if(lenA - i == 0) a.insert(a.begin(), '1');
                else a[lenA - i - 1] += 1;
            }
        }
        return a;
    }
};

int main() {
    while(true) {
        Solution solution;
        string a, b;
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;

        cout << solution.addBinary(a, b);
    }
    
    return 0;
}