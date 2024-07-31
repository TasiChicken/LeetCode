#include <iostream>
#include <vector>
#include <queue>

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
    int direc[5] = {1, 0, -1, 0, 1};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        bool visit[m][n];
        priority_queue<vector<int>> pq;
        int cnt = m * n, ans = 0;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(visit[i][j] = (i == 0 || j == 0 || i == m - 1 || j == n - 1))
                    pq.push({-heightMap[i][j], i, j}), cnt--;

        while(cnt){
            auto top = pq.top();
            pq.pop();

            for(int i = 0; i < 4; i++){
                int x = top[1] + direc[i], y = top[2] + direc[i + 1];
                if(x < 0 || x >= m || y < 0 || y >= n || visit[x][y])
                    continue;
                visit[x][y] = 1;
                cnt--;
                ans += max(-top[0] - heightMap[x][y], 0);
                pq.push({min(top[0], -heightMap[x][y]), x, y});
            }
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "heightMap = ";
        cin >> s;
        auto heightMap = parse(s);

        cout << solution.trapRainWater(heightMap) << endl;
    }
    
    return 0;
}