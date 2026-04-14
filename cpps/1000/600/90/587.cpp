#include <bits/stdc++.h>

using namespace std;

class Solution {
    int cross_prod(const vector<int>& o, const vector<int>& a, const vector<int>& b){
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0]);
    }
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());

        vector<vector<int>> upper, lower;
        for(int i = 0; i < trees.size(); i++){
            while(lower.size() > 1 && 
                cross_prod(lower[lower.size() - 2], lower.back(), trees[i]) < 0)
                lower.pop_back();

            lower.push_back(trees[i]);
        }

        for(int i = trees.size() - 1; i >= 0; i--){
            while(upper.size() > 1 && 
                cross_prod(upper[upper.size() - 2], upper.back(), trees[i]) < 0)
                upper.pop_back();

            upper.push_back(trees[i]);
        }
        reverse(upper.begin(), upper.end());

        int idx = 0, n = lower.size();
        for(int i = 0; i < n; i++){
            while(upper[idx] < lower[i]) 
                lower.push_back(upper[idx++]);

            if(upper[idx] == lower[i]) idx++;
        }

        return lower;
    }
};

void print(vector<vector<int>> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j];
            if(j != v[i].size() - 1) cout << ",";    
        }
        cout << "]";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

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

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        auto trees = parse(s);

        print(solution.outerTrees(trees));
    }
    
    return 0;
}