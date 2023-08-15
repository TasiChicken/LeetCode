#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.size(); i++) 
            if(match(haystack, needle, i)) return i;
        return -1;
    }
private:
    bool match(string haystack, string needle, int i) {
        for(int j = 0; j < needle.size(); j++)
            if(haystack[i + j] != needle[j]) return false;
        return true;
    }
};

int main()
{
    Solution solution;

    while(true) {
        string haystack, needle;
        cout << "haystack = ";
        cin >> haystack;
        cout << "needle = ";
        cin >> needle;

        cout << solution.strStr(haystack, needle) << endl;
    }
    
    return 0;
}