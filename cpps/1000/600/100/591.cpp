#include <bits/stdc++.h>

using namespace std;

class Solution {
    const string cdata_prefix = "<![CDATA[";
    bool isTAG_CONTENT(string code){
        int idx = 0;

        stack<pair<int, int>> st;
        while(idx < code.size()){
            auto l = code.find("<", idx);
            if(l == string::npos) break;

            idx = l;

            if(code[idx + 1] == '/'){
                if(st.empty()) return false;

                auto t = st.top();
                st.pop();
                for(int i = 0; i < t.second; i++)
                    if(idx + 2 + i >= code.size() || code[idx + 2 + i] != code[t.first + i])
                        return false;

                idx += t.second + 1;
                continue;
            }

            if(code[idx + 1] == '!'){
                for(int i = 2; i < cdata_prefix.size(); i++)
                    if(idx + i >= code.size() || code[idx + i] != cdata_prefix[i])
                        return false;

                auto r = code.find("]]>", idx + cdata_prefix.size());
                if(r == string::npos) return false;

                idx = r + 1;
                continue;
            }

            int name_len = getValidTagNameLen(code.substr(idx));
            if(name_len == -1) return false;
            st.emplace(idx + 1, name_len + 1);

            idx += name_len + 2;
        }
        return st.empty();
    }
    int getValidTagNameLen(string code){
        if(code[0] != '<') return -1;

        int name_len = 0;
        for(int i = 1 ; i < 11; i++)
            if(i >= code.size()) return -1;
            else if(code[i] >= 'A' && code[i] <= 'Z')
                name_len++;
            else if(code[i] == '>')
                break;
            else return -1;

        if(name_len < 1 || name_len > 9) 
            return -1;

        return name_len;
    }
public:
    bool isValid(string code) {
        int name_len = getValidTagNameLen(code);
        if(name_len == -1) return false;

        for(int i = 0; i <= name_len; i++)
            if(code[code.size() - i - 1] != code[1 + name_len - i])
                return false;

        if(code[code.size() - name_len - 2] != '/') return false;
        if(code[code.size() - name_len - 3] != '<') return false;

        return isTAG_CONTENT(code.substr(2 + name_len, code.size() - 5 - name_len * 2));
    }
};

int main() {
    while(true) {
        Solution solution;
        string code;
        getline(cin, code);
        code = code.substr(1, code.size() - 2);

        cout << solution.isValid(code) << endl;
    }
    
    return 0;
}