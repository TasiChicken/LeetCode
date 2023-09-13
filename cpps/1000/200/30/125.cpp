#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> v;
        int size = 0;
        for(char c : s)
            if(c >= 'a' && c <= 'z') v.push_back(c - 'a'), size++;
            else if(c >= 'A' && c <= 'Z') v.push_back(c - 'A'), size++;
            else if(c >= '0' && c <= '9') v.push_back(c), size++;
        for(int i = 0; i < size >> 1; i++)
            if(v[i] != v[size - i - 1]) return false;
        return true;
    }
/*Optimized Solution
    char in(char c){
        if(c >= '0' && c <= '9') return c;
        if(c >= 'a' && c <= 'z') return c;
        if(c >= 'A' && c <= 'Z') return c - 'A' + 'a';
        return 0;
    }
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        char lc, rc;
        while(r > l){
            lc = in(s[l]);
            while(r > l && !lc) lc = in(s[++l]);
            rc = in(s[r]);
            while(r > l && !rc) rc = in(s[--r]);
            if(lc != rc) return false;
            r--, l++;
        }
        return true;
    }
*/
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;

        cout << solution.isPalindrome(s) << endl;
    }
    
    return 0;
}