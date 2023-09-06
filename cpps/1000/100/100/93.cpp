#include <iostream>
#include <vector>

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
    bool inside(string& s, int start){
        return s[start] == '1' || s[start] == '2' && 
        (s[start + 1] < '5' || s[start + 1] == '5' && s[start + 2] <= '5');
    }
    void recursion(vector<string>& ans, string& cur, string& s, int& len, int start, int index){
        if(len - start < index + 1 || len - start > (index + 1) * 3) return;
        
        if(!index--)
            if(len - start == 1 ||
            len - start == 2 && s[start] != '0' ||
            len - start == 3 && inside(s, start))
                return ans.push_back(cur + s.substr(start));
            else return;
        
        int i;
        for(i = 0; start < len && i < 3; i++){
            if(i == 1 && s[start - i] == '0' || 
            i == 2 && !inside(s, start - 2)) break;

            cur.push_back(s[start++]);
            cur.push_back('.');
            recursion(ans, cur, s, len, start, index);
            cur.pop_back();
        }
        while(i--) cur.pop_back();
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int len = s.length();
        string cur;
        cur.reserve(len + 3);
        recursion(ans, cur, s, len, 0, 3);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        
        print(solution.restoreIpAddresses(s));
    }
    
    return 0;
}