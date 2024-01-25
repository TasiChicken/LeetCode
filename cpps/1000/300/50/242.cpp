#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int bucket[26];
        for(auto c : s)
            bucket[c - 'a']++;
        
        for(auto c : t)
            if(!bucket[c - 'a']--) return false;
        return true;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s, t;
        cout << "s = ";
        cin >> s;
        cout << "t = ";
        cin >> t;
        cout << solution.isAnagram(s, t) << endl;
    }
    
    return 0;
}