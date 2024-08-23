#include <iostream>
#include <vector>
#include <algorithm>

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

vector<vector<int>> parse(string s){
    vector<vector<int>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
    return v;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        int ans = 0, r = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
            if(intervals[i][0] >= r)
                r = intervals[i][1];
            else ans++;
        return ans; 
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "intervals = ";
        cin >> s;
        auto intervals = parse(s);

        cout << solution.eraseOverlapIntervals(intervals) << endl;
    }
    
    return 0;
}