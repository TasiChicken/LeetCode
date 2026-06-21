#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int> pos, neg;
        
        for(int n : nums){
            pos.emplace(n);
            neg.emplace(-n);
            
            if(pos.size() > 2) pos.pop();
            if(neg.size() > 3) neg.pop();
        }

        vector<int> l, g;
        while(pos.size()) l.push_back(pos.top()), pos.pop();
        while(neg.size()) g.push_back(-neg.top()), neg.pop();

        return max(g[0] * g[1] * g[2], l[0] * l[1] * g[2]);
    }
};

vector<int> parse_(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}


int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        auto nums = parse_(s);

        cout << solution.maximumProduct(nums) << endl;
    }
    
    return 0;
}