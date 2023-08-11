#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        vector<string> ans;

        if(len > 0)
            recursion(ans, digits, len, 0, "");

        return ans;
    }
private:
    void recursion(vector<string> &ans, string digits, int len, int index, string cur) {
        if(index == len) {
            ans.push_back(cur);
            return;
        }

        char c = digits[index];
        int times = (c == '7' || c == '9') ? 4 : 3;
        int start = (c - '2') * 3 + (c > '7') + 'a';
        for(int i = 0; i < times; i++)
            recursion(ans, digits, len, index + 1, cur + (char)(i + start));
    }
/* Optomzied Solution(maybe)
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        vector<string> ans;

        if(len > 0)
            recursion(ans, digits, len, 0, new char[len]);

        return ans;
    }
private:
    void recursion(vector<string> &ans, string digits, int len, int index, char* cur) {
        if(index == len) {
            ans.push_back(string(cur, len));
            return;
        }

        char c = digits[index];
        int times = (c == '7' || c == '9') ? 4 : 3;
        int start = (c - '2') * 3 + (c > '7') + 'a';
        for(int i = 0; i < times; i++){
            cur[index] = (i + start);
            recursion(ans, digits, len, index + 1, cur);
        }
    }
*/
};

string print_output(vector<string> output) {
    string output_string = "[";
    for(int i = 0; i < output.size(); i++) {
        output_string += "\"" + output[i] + "\"";
        if(i != output.size() - 1)
            output_string += ",";
    }
    output_string += "]";

    return output_string;
}

int main()
{
    Solution solution;

    while(true) {
        string digits;
        cout << "digits = ";
        cin >> digits;

        cout << print_output(solution.letterCombinations(digits)) << endl;
    }
    
    return 0;
}