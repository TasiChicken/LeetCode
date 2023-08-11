#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i = 0; ; i++)
            for(string str : strs)
                if(i >= str.length() || str[i] != strs[0][i]) return str.substr(0, i);
    }
/* optimized solution
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = INT_MAX;
        string criteria = strs[0];
        for(string str : strs){
            int len = str.length();
            if(len < minLen)
                minLen = len;
        }

        for(int i = 0; i < minLen; i++){
            for(auto str = strs.begin() + 1; str != strs.end(); str++)
                if((*str)[i] != criteria[i]) return criteria.substr(0, i);
        }
        return criteria.substr(0, minLen);
    }
*/
};

vector<string> parse_input(string input) {
    vector<string> strs;
    input.erase(input.length() - 1, 1);
    input.erase(0, 1);

    if(input.length() == 0) return strs;

    int index = 0;
    for(int i = 0; i <= input.length(); i++) 
        if(input[i] == ',' || i == input.length()) {
            strs.push_back(input.substr(index + 1, i - index - 2));
            index = i + 1;
        }

    return strs;
}

int main()
{
    Solution solution;

    while(true) {
        string input;
        vector<string> strs;

        cout << "nums = ";
        cin >> input;
        strs = parse_input(input);


        cout << "\"" << solution.longestCommonPrefix(strs) << "\"" << endl;
    }
    
    return 0;
}