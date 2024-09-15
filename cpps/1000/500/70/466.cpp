#include <iostream>

using namespace std;

class Solution {
    int mp[100][26] = {};
    int ending[100] = {};
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int n = s1.size(), m = s2.size();
        for(int i = 0; i < n; i++)
            if(!mp[n - 1][s1[i] - 'a'])
                mp[n - 1][s1[i] - 'a'] = 1 + i;
        for(int i = n - 1; i > 0; i--)
            for(int j = 0; j < 26; j++)
                if(mp[i][j])
                    mp[i - 1][j] = 1 + (s1[i] == 'a' + j ? 0 : mp[i][j] % n);

        int s2_freq = 0, s1_rep = 0, s1_idx = n - 1, ans = 0;
        while(true){
            for(int i = 0; i < m; i++){
                if(!mp[s1_idx][s2[i] - 'a']) return 0;
                s1_idx += mp[s1_idx][s2[i] - 'a'];
                s1_rep += s1_idx / n;
                s1_idx %= n;
                if(s1_rep > n1) return (ans + s2_freq) / n2;
            }
            s2_freq++;

            if(ans) continue;

            if(ending[s1_idx]) {
                int interval = s1_rep - ending[s1_idx];
                ans = 1 + (n1 - ending[s1_idx]) / interval * (s2_freq - 1);
                s1_rep = n1 - (n1 - ending[s1_idx]) % interval;
                s2_freq = 0;
            }
            ending[s1_idx] = s1_rep;
        }
    }
};

int main() {
    while(true) {
        Solution solution;
        string s1;
        cout << "s1 = ";
        cin >> s1;
        s1 = s1.substr(1, s1.size() - 2);
        int n1;
        cout << "n1 = ";
        cin >> n1;
        string s2;
        cout << "s2 = ";
        cin >> s2;
        s2 = s2.substr(1, s2.size() - 2);
        int n2;
        cout << "n2 = ";
        cin >> n2;

        cout << solution.getMaxRepetitions(s1, n1, s2, n2) << endl;
    }
    
    return 0;
}