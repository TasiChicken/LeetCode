#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp(26);
        for(char c : s1)
            mp[c - 'a']++;

        int cnt = s1.size(), left = 0;
        for(int i = 0; i < s2.size(); i++){
            if(mp[s2[i] - 'a'] > 0){
                mp[s2[i] - 'a']--;
                if(--cnt == 0) return true;

                continue;
            }

            while(left < i && mp[s2[i] - 'a'] < 1){
                mp[s2[left++] - 'a']++;
                cnt++;
            }

            if(mp[s2[i] - 'a'] < 1) {
                left++;
                continue;
            }

            mp[s2[i] - 'a']--;
            if(--cnt == 0) return true;

        }

        return false;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s1, s2;
        cin >> s1 >> s2;
        s1 = s1.substr(1, s1.size() - 2);
        s2 = s2.substr(1, s2.size() - 2);

        cout << solution.checkInclusion(s1, s2) << endl;
    }
    
    return 0;
}