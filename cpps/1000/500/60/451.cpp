#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> mp(26 * 2 + 10);

        for(int i = 0; i < 10; i++)
            mp[i].second = '0' + i;
        for(int i = 0; i < 26; i++)
            mp[10 + i].second = 'a' + i;
        for(int i = 0; i < 26; i++)
            mp[36 + i].second = 'A' + i;

        for(char c : s)
            if(c >= '0' && c <= '9')
                mp[c - '0'].first--;
            else if(c >= 'a' && c <= 'z')
                mp[10 + c - 'a'].first--;
            else mp[36 + c - 'A'].first--;
        
        sort(mp.begin(), mp.end());
        string ans = ""; 
        for(auto p : mp)
            if(!p.first) break;
            else ans.append(string(-p.first, p.second));

        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        s = s.substr(1, s.size() - 2);

        cout << solution.frequencySort(s) << endl;
    }
    
    return 0;
}