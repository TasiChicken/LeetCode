#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool check(vector<int>& mp, int k, int len){
        for(int i = 0; i < 26; i++)
            if(mp[i] + k >= len)
                return true;
        return false;
    }
public:
    int characterReplacement(string s, int k) {
        vector<int> mp(26);
        int i = 0, j = 0, ans = 0;
        while(j < s.size()){
            while (!check(mp, k, j - i))
                mp[s[i++] - 'A']--;
            while(j < s.size() && check(mp, k, j - i))
                mp[s[j++] - 'A']++;
            ans = max(ans, j - i - !check(mp, k, j - i));
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        int k;
        cout << "k = ";
        cin >> k;

        cout << solution.characterReplacement(s, k) << endl;
    }
    
    return 0;
}