#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

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
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        unordered_map<float, int> mp;
        int len = points.size();
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++){
                float scope = points[j][1] - points[i][1];
                scope = scope ? (points[j][0] - points[i][0]) / scope : INFINITY;
                ans = max(ans, ++mp[scope]);
            }
            mp.clear();
        }
        return ans + 1;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "points = ";
        cin >> s;
        auto points = parse(s);

        cout << solution.maxPoints(points) << endl;
    }
    
    return 0;
}