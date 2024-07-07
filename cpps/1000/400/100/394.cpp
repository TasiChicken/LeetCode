#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        vector<pair<int, string>> st;
        if(s[0] >= 'a' || s[0] <= 'z') 
            st.push_back({1, ""});

        int num = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z') 
                st.back().second.push_back(s[i]);
            if(s[i] >= '0' && s[i] <= '9')
                num = num * 10 + s[i] - '0';
            if(s[i] == '['){
                st.push_back({num, ""});
                num = 0;
            }
            if(s[i] == ']'){
                auto code = st.back();
                st.pop_back();
                for(int j = 0; j < code.first; j++)
                    st.back().second += code.second;
            }

        }
        return st[0].second;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        cout << solution.decodeString(s) << endl;
    }
    
    return 0;
}