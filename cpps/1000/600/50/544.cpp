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

#define maxn 105
// [b_idx]    color, cnt, c_idx
vector<pair<int, pair<int, int>>> bs;
// [color][c_idx]   b_idx
vector<int> cs[maxn];
// [l][r][cnt]  point
int dp[maxn][maxn][maxn];

class Solution {
    void init(){
        bs.clear();
        for(int i = 0; i < maxn; i++)
            cs[i].clear();
        for(int i = 0; i < maxn; i++)
            for(int j = i + 1; j < maxn; j++)
                for(int k = 0; k < maxn; k++)
                    dp[i][j][k] = 0;
    }
    void build_bs(int color, int cnt){
        int idx = bs.size();
        bs.push_back({color, {cnt, cs[color].size()}});
        cs[color].push_back(idx);
    }
    int recursion(int l, int r, int k){
        if(l > r) return 0;
        int cnt = bs[l].second.first;
        if(l == r) return (k + cnt) * (k + cnt);
        if(dp[l][r][k]) return dp[l][r][k];

        int color = bs[l].first;
        int c_idx = bs[l].second.second;

        int ans = (k + cnt) * (k + cnt) + recursion(l + 1, r, 0);
        for(int i = c_idx + 1; i < cs[color].size() && cs[color][i] <= r; i++)
            ans = max(ans, recursion(l + 1, cs[color][i] - 1, 0) + recursion(cs[color][i], r, k + cnt));
        return dp[l][r][k] = ans;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        init();

        int color = boxes[0], cnt = 1;
        for(int i = 1; i < boxes.size(); i++)
            if(boxes[i] != color){
                build_bs(color, cnt);
                color = boxes[i];
                cnt = 1;
            }
            else cnt++;
        build_bs(color, cnt);
       
        return recursion(0, bs.size() - 1, 0);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "boxes = ";
        cin >> s;
        auto boxes = parse_(s);

        cout << solution.removeBoxes(boxes) << endl;
    }
    
    return 0;
}