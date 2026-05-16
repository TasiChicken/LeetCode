#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26);
        int total = 0;
        for(char c : tasks)
            cnt[c - 'A']++, total++;

        int max_cnt = 0, num = 0;
        for(int i = 0; i < 26; i++)
            if(cnt[i] > max_cnt)
                max_cnt = cnt[i], num = 1;
            else if(cnt[i] == max_cnt)
                num++;

        return max(total, (max_cnt - 1) * (n + 1) + num);
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

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        auto tasks = parse_(s);
        int n;
        cin >> n;

        cout << solution.leastInterval(tasks, n) << endl;
    }
    
    return 0;
}