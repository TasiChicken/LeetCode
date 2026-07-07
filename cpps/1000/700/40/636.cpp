#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);

        vector<int> st;
        int time = 0;

        for(string s : logs){
            auto i1 = s.find(':');
            auto i2 = s.find(':', i1 + 1);

            int id = stoi(s.substr(0, i1));
            int timestamp = stoi(s.substr(i2 + 1));
            bool is_start = s[i1 + 1] == 's';

            if(is_start){
                if(!st.empty())
                    ans[st.back()] += timestamp - time;

                st.push_back(id);
                time = timestamp;
            }else{
                ans[id] += timestamp - time + 1;
                st.pop_back();
                time = timestamp + 1;
            }
        }

        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}