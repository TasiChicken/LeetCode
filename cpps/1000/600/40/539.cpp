#include <bits/stdc++.h>

using namespace std;

vector<string> parse_(string s){
    vector<string> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(s.substr(last + 1, i - last - 2));
            last = i + 1;
        }
    return v;
}

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> temp;
        for(auto& t : timePoints)
            temp.push_back(stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2)));

        sort(temp.begin(), temp.end());
        int ans = 24 * 60 - temp.back() + temp.front();

        for(int i = 1; i < temp.size(); i++)
            ans = min(ans, temp[i] - temp[i - 1]);

        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "timePoints = ";
        cin >> s;
        auto timePoints = parse_(s);

        cout << solution.findMinDifference(timePoints) << endl;
    }
    
    return 0;
}