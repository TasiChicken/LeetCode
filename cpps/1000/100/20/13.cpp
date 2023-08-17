#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int len = s.size();
        int last = romans.at(s[0]);
        for(int i = 1; i < len; i++)
        {
            int cur = romans.at(s[i]);
            ans += cur > last ? -last : last;

            last = cur;
        }
        return ans + last;
    }
private:
    const unordered_map<char, int> romans = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
};

int main()
{
    Solution solution;

    while(true) {
        string s;
        cout << "s = ";
        cin >> s;
        cout << solution.romanToInt(s) << endl;
    }
    
    return 0;
}