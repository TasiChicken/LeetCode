#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        int len = senate.size();
        for(int i = 0; i < len; i++)
            if(senate[i] == 'R') r.push(i);
            else d.push(i);

        while(r.size() && d.size()){
            if(r.front() < d.front()){
                d.pop();
                r.push(r.front() + len);
                r.pop();
                continue;;
            }

            r.pop();
            d.push(d.front() + len);
            d.pop();
        }

        return r.size() ? "Radiant" : "Dire";
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}