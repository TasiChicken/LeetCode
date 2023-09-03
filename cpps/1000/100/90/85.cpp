#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void getAns(vector<char>& hs, int& n, int& ans, vector<int> &last){
        int ptr = -1, h, w;
        for(int i = 0; i < n; i++){
            while(ptr >= 0 && hs[i] < hs[last[ptr]]){
                h = (int)hs[last[ptr--]] - CHAR_MIN;
                w = i - (ptr >= 0 ? last[ptr] + 1 : 0);
                ans = max(ans, w * h);
            }
            last[++ptr] = i;
        }
        while (ptr >= 0 && hs[last[ptr]] > CHAR_MIN){
            h = (int)hs[last[ptr--]] - CHAR_MIN;
            w = n - (ptr >= 0 ? last[ptr] + 1 : 0);
            ans = max(ans, w * h);
        }
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        for(int j = 0; j < n; j++)
            matrix[0][j] = CHAR_MIN + (matrix[0][j] == '1');
        
        vector<int> last(n);
        for(int i = 1; i < m; i++){
            bool got = false;
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == '0'){
                    matrix[i][j] = CHAR_MIN;
                    if(!got)
                        getAns(matrix[i - 1], n, ans, last), got = true;
                }
                else matrix[i][j] = matrix[i - 1][j] + 1;
        }
        getAns(matrix.back(), n, ans, last);
        return ans;
    }
};

vector<char> parse_(string s){
    vector<char> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(s[last + 1]);
            last = i + 1;
        }
    return v;
}

vector<vector<char>> parse(string s){
    vector<vector<char>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
    return v;
}

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "matrix = ";
        cin >> s;
        auto matrix = parse(s);
        
        cout << solution.maximalRectangle(matrix) << endl;
    }
    
    return 0;
}