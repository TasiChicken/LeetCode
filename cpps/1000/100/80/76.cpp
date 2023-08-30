#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length(), left = 0, right = 0, len = INT_MAX;
        string ans;
        unordered_map<char, int> mp;
        for(char c : t) mp[c]++;
        
        auto it = mp.find(s[right]);
        while(left == right && right < m && it == mp.end())
            it = mp.find(s[right = ++left]);
        if(right == m) return "";
        it->second--, n--;

        while(true){
            while(n && ++right < m)
                if((it = mp.find(s[right])) != mp.end() && it->second-- > 0) n--;
            if(n) return ans;

            for(; !n && left <= right; left++)
                if((it = mp.find(s[left])) != mp.end() && it->second++ == 0){
                    if(right - left + 1 < len)
                        ans = s.substr(left, len = right - left + 1);
                    n = 1;
                }
        }
    }
/* Optimized Solution
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length(), left = 0, right = 0, len = INT_MAX, start = 0;
        unordered_map<char, int> mp;
        for(char c : t) mp[c]++;
        
        unordered_map<char, int>::iterator it;
        while(right < m){
            while(n && right < m)
                if((it = mp.find(s[right++])) != mp.end() && it->second-- > 0) n--;
            for(; !n && left <= right; left++)
                if((it = mp.find(s[left])) != mp.end() && it->second++ == 0){
                    if(right - left < len)
                        start = left, len = right - left;
                    n = 1;
                }
        }
        return len > m ? "" : s.substr(start, len);
    }
*/
};

int main() {
    while(true) {
        Solution solution;
        string s, t;
        cout << "s = ";
        cin >> s;
        cout << "t = ";
        cin >> t;

        cout << solution.minWindow(s, t) << endl;
    }
    
    return 0;
}