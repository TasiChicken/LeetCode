#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        string news = "^";
        for (char c : s) {
            news += c;
            news += "#";
        }
        news.pop_back();
        news += "$";

        int res = 0;

        vector<int> v(news.size());
        int cen = 0, r = 0;

        for(int i = 1; i < v.size() - 1; i++){
            int mir = 2 * cen - i;

            if(i < r) v[i] = min(r - i, v[mir]);

            while(news[i - v[i] - 1] == news[i + v[i] + 1]) v[i]++;

            if(i + v[i] > r) cen = i, r = i + v[i];

            if(i & 1) res += 1 + v[i] / 2;
            else if(v[i]) res += (v[i] + 1) / 2;
        }

        return res;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;

        cout << solution.countSubstrings(s) << endl;
    }
    
    return 0;
}