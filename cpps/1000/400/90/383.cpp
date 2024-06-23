#include <iostream>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mag[26];
        for(int i = 0; i < 26; i++)
            mag[i] = 0;
        for(char c : magazine)
            mag[c - 'a']++;
        for(char c : ransomNote)
            if(mag[c - 'a']-- == 0)
                return false;
        return true;
    }
};

int main() {
    while(true) {
        Solution solution;
        string ransomNote;
        string magazine;

        cout << "ransomNote = ";
        cin >> ransomNote;
        cout << "magazine = ";
        cin >> magazine;

        cout << solution.canConstruct(ransomNote, magazine);
    }
    
    return 0;
}