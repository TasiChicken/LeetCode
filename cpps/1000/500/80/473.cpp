#include <iostream>
#include <vector>

using namespace std;

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

class Solution {
    bool recursion(vector<int>& matchsticks, int tar, int cur, int used, int side, vector<int>& mp){
        if(mp[used] >= 0) return mp[used] == 1;
        if(cur == tar){
            if(side == 2) return mp[used] = true;
            for(int i = 0; i < matchsticks.size(); i++)
                if(!(used & (1 << i)))
                    return mp[used] = recursion(matchsticks, tar, matchsticks[i], used | (1 << i), side + 1, mp);
        }

        for(int i = 0; i < matchsticks.size(); i++)
            if(!(used & (1 << i)) && cur + matchsticks[i] <= tar && recursion(matchsticks, tar, cur + matchsticks[i], used | (1 << i), side, mp))
                return mp[used] = true;
        return mp[used] = false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int longest = 0, sum = 0;
        for(int n : matchsticks)
            longest = max(longest, n), sum += n;
        if(sum % 4) return false;
        sum /= 4;
        if(longest > sum) return false;

        vector<int> mp(1 << matchsticks.size(), -1);
        return recursion(matchsticks, sum, matchsticks[0], 1, 0, mp);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "matchsticks = ";
        cin >> s;
        auto matchsticks = parse_(s);

        cout << solution.makesquare(matchsticks) << endl;
    }
    
    return 0;
}