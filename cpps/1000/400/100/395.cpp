#include <iostream>

using namespace std;

class Solution {
    int mp[26];
    int recursion(string& s, int k, int l, int r){
        if(k > r - l + 1) return 0;

        for(int i = 0; i < 26; i++)
            mp[i] = 0;
        for(int i = l; i <= r; i++)
            mp[s[i] - 'a']++;
        
        int start = 0, ans = 0, split = 0;
        for(int i = 0; i < 26; i++)
            if(mp[i] && mp[i] < k)   
                split |= 1 << i;
        if(!split) return r - l + 1;

        for(int i = l; i <= r; i++)
            if((1 << (s[i] - 'a')) & split){
                ans = max(ans, recursion(s, k, start, i - 1));
                start = i + 1;
            }
        ans = max(ans, recursion(s, k, start, r));
        return ans;
    }
public:
    int longestSubstring(string s, int k) {
        return recursion(s, k, 0, s.size() - 1);
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


        cout << solution.longestSubstring(s, k) << endl;
    }
    
    return 0;
}