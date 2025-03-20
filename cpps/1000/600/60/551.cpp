#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int a = s[0] == 'A', cl = s[0] == 'L';
        for(int i = 1; i < s.size(); i++)
            if(s[i] == 'L'){
                if(++cl >= 3) return false;
            }
            else{
                cl = 0;
                if(s[i] == 'A' && ++a >= 2) return false;
            }
        return true;
    }
};

int main() {
    while(true){
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;

        cout << solution.checkRecord(s) << endl;

    }
    
    return 0;
}