#include <iostream>

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string password) {
        int lack = 0;
        for(char c : password)
            if(c >= '0' && c <= '9')
                lack |= 1;
            else if(c >= 'a' && c <= 'z')
                lack |= 2;
            else if(c >= 'A' && c <= 'Z')
                lack |= 4;
        for(int i = 3; i > 0; i--)
            lack =  (((lack & 1) << i) + lack) >> 1;
        lack = 3 - lack;

        if(password.size() < 6)
            return max(6 - (int)password.size(), lack);

        if(password.size() < 21){
            int ans = 0, rep = 1;
            for(int i = 1; i < password.size(); i++)
                if(password[i] == password[i - 1])
                    rep++;
                else {
                    ans += rep / 3;
                    rep = 1;
                }
            ans += rep / 3;
            return ans;
        }

        int step = 0, rep = 1, _3 = 0, _2 = 0, _1 = 0, del = 0;
        for(int i = 1; i < password.size(); i++)
            if(password[i] == password[i - 1])
                rep++;
            else {
                if(rep > 2){
                    step += rep / 3;
                    if(rep % 3 == 1) _1++;
                    else if(rep % 3 == 2) _2++;
                    else _3++;
                    del += rep - 2;
                }
                rep = 1;
            }
        if(rep > 2){
            step += rep / 3;
            if(rep % 3 == 1) _1++;
            else if(rep % 3 == 2) _2++;
            else _3++;
            del += rep - 2;
        }

        int rev = password.size() - 20;
        if(del <= rev)
            return rev + lack;

        step -= min(rev, _3); 
        rev -= min(rev, _3);
        if(rev > 1){
            step -= min(rev / 2, _1);
            rev -= min(rev / 2, _1) * 2;
        }
        if(rev > 2){
            step -= rev / 3;
            rev %= 3;
        }

        return max(step, lack) + password.size() - 20;
    }
};

int main() {
    while(true) {
        Solution solution;
        string password;
        cout << "password = ";
        cin >> password;

        cout << solution.strongPasswordChecker(password) << endl;
    }
    
    return 0;
}