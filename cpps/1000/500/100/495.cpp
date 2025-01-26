#include <bits/stdc++.h>

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
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = duration;
        for(int i = 1; i < timeSeries.size(); i++)
            ans += min(timeSeries[i] - timeSeries[i - 1], duration);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        cin >> s;
        auto timeSeries = parse_(s);
        int duration;
        cout << "duration = ";
        cin >> duration;

        cout << solution.findPoisonedDuration(timeSeries, duration) << endl;
    }
    
    return 0;
}