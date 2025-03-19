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

vector<vector<int>> parse(string s){
    vector<vector<int>> v;
    int last;
    for(int i = 1; i < s.length() - 1; i++)
        if(s[i] == '[') last = i;
        else if(s[i] == ']') v.push_back(parse_(s.substr(last, i - last + 1)));
    return v;
}

#define maxn 200
int roots[maxn], ranks[maxn];

int find_root(int idx){
    if(roots[idx] == idx) return idx;
    return roots[idx] = find_root(roots[idx]);
}

bool merge(int a, int b){
    a = find_root(a);
    b = find_root(b);
    if(a == b) return false;

    if(ranks[a] < ranks[b]) swap(a, b);
    ranks[a] += ranks[b];
    roots[b] = a;

    return true;
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for(int i = 0; i < n; i++)
            roots[i] = i, ranks[i] = 1;

        int ans = n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(isConnected[i][j])
                    ans -= merge(i, j);

        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "isConnected = ";
        cin >> s;
        auto isConnected = parse(s);
        cout << solution.findCircleNum(isConnected) << endl;
    }
    
    return 0;
}