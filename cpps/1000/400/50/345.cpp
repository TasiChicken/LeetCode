#include <iostream>

using namespace std;

class Solution {
    const string vowels = "aeiou";
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r){
            while(l < r && vowels.find(s[l]) == string::npos) l++;
            while(l < r && vowels.find(s[r]) == string::npos) r--;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        s = s.substr(1, s.size() - 2);

        cout << "\"" << solution.reverseVowels(s) << "\"" <<  endl;
    }
    
    return 0;
}