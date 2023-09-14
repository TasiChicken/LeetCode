#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int len = s.length(), *ans = new int[len + 1];
        for(int i = 0; i <= len; i++) ans[i] = i - 1;

        for(int i = 1; i <= len; i++){
            for(int j = 0; i >= j && i + j < len && s[i - j] == s[i + j]; j++)
                ans[i + j + 1] = min(ans[i + j + 1], ans[i - j] + 1);
            for(int j = 0; i > j && i + j < len && s[i - j - 1] == s[i + j]; j++)
                ans[i + j + 1] = min(ans[i + j + 1], ans[i - j - 1] + 1);
        }
        return ans[len];
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;

        cout << solution.minCut(s) << endl;
    }
    
    return 0;
}