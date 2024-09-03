#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<long long, int> dp[points.size()];
        int ans = 0;
        for(int i = 1; i < points.size(); i++){
            for(int j = 0; j < i; j++){
                int d_x = points[i][0] - points[j][0];
                int d_y = points[i][1] - points[j][1];
                int d = d_x * d_x + d_y * d_y;

                if(dp[j].find(d) != dp[j].end())
                    ans += dp[j][d] * 2;
                if(dp[i].find(d) != dp[i].end())
                    ans += dp[i][d] * 2;

                dp[i][d]++, dp[j][d]++;
            }
        }
        return ans;
    }
/* Optimized Solution
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> dis(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < 2; k++)
                    dis[i][j] += (points[i][k] - points[j][k]) * (points[i][k] - points[j][k]);
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            sort(dis[i].begin(), dis[i].end());
            int cnt = 1;
            for(int j = 1; j <= n; j++)
                if(j == n || dis[i][j] != dis[i][j - 1]){
                    ans += cnt * (cnt - 1);
                    cnt = 1;
                }
                else cnt++;
        }
        return ans;
    }
 */
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "points = ";
        cin >> s;
        auto points = parse(s);

        cout << solution.numberOfBoomerangs(points) << endl;
    }
    
    return 0;
}