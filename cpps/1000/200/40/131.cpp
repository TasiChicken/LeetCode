#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<string>> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout << '\'' << v[i][j] << '\'';
            if(j != v[i].size() - 1) cout << ",";    
        }
        cout << "]";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    bool palindrome(string &s, int start, int end){
        if(start >= end) return true;
        return s[start] == s[end] && palindrome(s, start + 1, end - 1);
    }
    void recursion(vector<vector<string>>& ans, vector<string>& v, string& s, int start, int end){
        if(start == end) return ans.push_back(v);
        for(int i = start; i < end; i++)
            if(palindrome(s, start, i)){
                v.push_back(s.substr(start, i - start + 1));
                recursion(ans, v, s, i + 1, end);
                v.pop_back();
            }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        recursion(ans, v, s, 0, s.length());
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;

        print(solution.partition(s));
    }
    
    return 0;
}