#include <iostream>
#include <vector>

using namespace std;

vector<string> parse(string s){
    vector<string> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(s.substr(last + 1, i - last - 2));
            last = i + 1;
        }
    return v;
}

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> ans;
        int size = tokens.size(), st = 0;
        for(int i = 0; i < size; i++)
            if(tokens[i].size() > 1 || tokens[i][0] >= '0' && tokens[i][0] <= '9') ans.push_back(stoi(tokens[i])), st++;
            else if(tokens[i][0] == '+') ans[st - 1] += ans[--st], ans.pop_back();
            else if(tokens[i][0] == '-') ans[st - 1] -= ans[--st], ans.pop_back();
            else if(tokens[i][0] == '*') ans[st - 1] *= ans[--st], ans.pop_back();
            else if(tokens[i][0] == '/') ans[st - 1] /= ans[--st], ans.pop_back();
        return ans[0];
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "tokens = ";
        cin >> s;
        auto tokens = parse(s);

        cout << solution.evalRPN(tokens) << endl;
    }
    
    return 0;
}