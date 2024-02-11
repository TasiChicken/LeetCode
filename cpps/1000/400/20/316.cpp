#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> idx(26,  -1);

        for(int i = 0; i < s.size(); i++)
            idx[s[i] - 'a'] = i;
        
        string ans;
        vector<bool> ins(26, false);
        for(int i = 0; i < s.size(); i++){
            if(ins[s[i] - 'a']) continue;

            while(!ans.empty() && s[i] < ans.back() && idx[ans.back() - 'a'] > i) 
                ins[ans.back() - 'a'] = false, ans.pop_back();
            ins[s[i] - 'a'] = true, ans.push_back(s[i]);
        }

        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;

        cout << solution.removeDuplicateLetters(s) << endl;
    }
    
    return 0;
}