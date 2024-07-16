#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string removeKdigits(string& num, int k) {
        vector<char> st;
        int rem = k;
        for(int i = 0; rem ? i < num.size() : st.size() < num.size() - k; i++){
            while(rem && !st.empty() && st.back() > num[i])
                st.pop_back(), rem--;
            st.push_back(num[i]);
        }

        string ans = "0";
        for(int i = 0; i < num.size() - k; i++)
            if(ans.size() == 1 && ans[0] == '0') ans[0] = st[i];
            else ans.push_back(st[i]);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string num;
        cout << "num = ";
        cin >> num;
        int k;
        cout << "k = ";
        cin >> k;
        cout << solution.removeKdigits(num, k) << endl;
    }
    
    return 0;
}