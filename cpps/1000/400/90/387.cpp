#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int, int>> dict(26, {-1, 0});
        for(int i = 0; i < s.size(); i++)
            if(dict[s[i] - 'a'].second++ == 0)
                dict[s[i] - 'a'].first = i;
        int ans = s.size();
        for(auto p : dict)
            if(p.second == 1)
                ans = min(ans, p.first);
        return ans == s.size() ? -1 : ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        
        cout << solution.firstUniqChar(s) << endl;
    }
    
    return 0;
}