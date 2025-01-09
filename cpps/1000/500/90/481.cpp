#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if(n < 4) return 1;
        
        queue<bool> s;
        n -= 3;
        s.emplace(1);

        int res = 1;
        bool cur = 0;

        while(true){
            for(int i = 0; i <= s.front(); i++){
                s.emplace(cur);
                if(!cur) res++;
                if(--n <= 0) return res;
            }

            s.pop();
            cur = !cur;
        }
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;

        cout << solution.magicalString(n) << endl;
    }
    
    return 0;
}