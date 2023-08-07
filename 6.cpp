#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        int len = s.length();
        int dist = 2 * numRows - 2;
        
        char* ans = new char[len];
        int ansIndex = 0;

        for(int i = 0; i < numRows; i++) {
            int count = dist - 2 * i;
            int index = i;
            while (index < len) {
                ans[ansIndex++] = s[index];

                if(count == 0) count = dist;

                index += count;
                count = dist - count;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    while(true) {
        string s;
        int numRows;

        cout << "s = ";
        cin >> s;
        cout << "numRows = ";
        cin >> numRows;

        cout << solution.convert(s, numRows) << endl;
    }
    return 0;
}
