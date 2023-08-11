#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int repeatIndex = 0;
        int len;
        int i;
        int ans = 0;

        for(i = 0; i < s.length(); ) {
            char c = s[i++];
            int result = map[c];

            if(result != 0)  {
                len = i - 1 - repeatIndex;
                if(ans < len) ans = len;
                if(repeatIndex < result) repeatIndex = result;
            }
            map[c] = i;
        }
        len = i - repeatIndex;
        if(ans < len) ans = len;

        return ans;
    }
};

int main()
{
    Solution solution;

    while(true){
        string s;
        cout << "s = ";
        cin >> s;
        cout << solution.lengthOfLongestSubstring(s) << endl;
    }

    return 0;
}