#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        vector<int> cnt(10);

        for(int i = s.size() - 1; i > 0; i--){
            cnt[s[i] - '0']++;

            if(s[i] > s[i - 1]){
                int dig = s[i - 1] - '0';

                for(int j = dig + 1; j < 10; j++)
                    if(cnt[j]){
                        cnt[j]--;
                        s[i - 1] = '0' + j;
                        cnt[dig]++;
                        break;
                    }

                int idx = s.size() - 1;
                for(int j = 9; j >= 0; j--)
                    while(cnt[j]--)
                        s[idx--] = '0' + j;

                unsigned long long res = stoull(s);
                if(res > INT_MAX) return -1;

                return res;
            }
        }

        return -1;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cin >> n;

        cout << solution.nextGreaterElement(n) << endl;
    }
    
    return 0;
}