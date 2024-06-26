#include <iostream>
#include <vector>

using namespace std;

    class Solution {
    public:
        char findTheDifference(string s, string t) {
            vector<int> mp(26);
            for(char c : s)
                mp[c - 'a']++;
            for(char c : t)
                if(--mp[c - 'a'] < 0)
                    return c;
            return -1;
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
        cout << solution.findTheDifference(s, t) << endl;
    }
    
}