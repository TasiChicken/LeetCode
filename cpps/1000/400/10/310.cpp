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

void print(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<vector<int>> adjs = vector<vector<int>>(n);
        vector<int> cnts = vector<int>(n);

        for(auto e : edges)
            for(int i = 0; i <= 1; i++)
                adjs[e[i]].push_back(e[!i]), cnts[e[i]]++;
        
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(cnts[i] == 1) q.push(i);
        
        vector<int> ans;
        while(!q.empty()){
            ans.clear();

            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for(auto adj : adjs[node])
                    if(--cnts[adj] == 1) q.push(adj);
            }
        }
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;
        string s;
        cout << "edges = ";
        cin >> s;
        auto edges = parse(s);

        print(solution.findMinHeightTrees(n, edges));
    }
    
    return 0;
}