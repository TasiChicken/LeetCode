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
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int ans = w;
        priority_queue<int> pq;
        
        vector<pair<int, int>> projects;
        for(int i = 0; i < capital.size(); i++)
            projects.emplace_back(capital[i], profits[i]);
        sort(projects.begin(), projects.end());

        for(int i = 0, idx = 0; i < k; i++){
            while(idx < projects.size() &&  ans >= projects[idx].first)
                pq.emplace(projects[idx++].second);

            if(pq.empty() || !pq.top()) return ans;

            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        int k, w;
        string s;
        cout << "k = ";
        cin >> k;
        cout << "w = ";
        cin >> w;
        cout << "profits = ";
        cin >> s;
        auto profits = parse_(s);
        cout << "capital = ";
        cin >> s;
        auto capital = parse_(s);

        cout << solution.findMaximizedCapital(k, w, profits, capital) << endl;
    }
    
    return 0;
}