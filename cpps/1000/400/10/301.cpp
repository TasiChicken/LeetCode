#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<string> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << '\"' << v[i] << '\"';
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    void recursion(vector<string>& ans, string s, int si, int sj, string rem){
        int cnt = 0;
        for(int i = si; i < s.size(); i++){
            if(s[i] == rem[0]) cnt++;
            else if(s[i] == rem[1]) cnt--;
            
            if(cnt >= 0) continue;

            for(int j = sj; j <= i; j++)
                if(s[j] == rem[1] && (!j || s[j] != s[j - 1])) 
                    recursion(ans, s.substr(0, j) + s.substr(j + 1), i, j, rem);
            return;
        }

        reverse(s.begin(), s.end());
        if(rem[0] == '(') return recursion(ans, s, 0, 0, ")(");
        ans.push_back(s);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        recursion(ans, s, 0, 0, "()");
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;

        print(solution.removeInvalidParentheses(s));
    }
    
    return 0;
}