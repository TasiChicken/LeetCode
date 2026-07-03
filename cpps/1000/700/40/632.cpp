#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int maxi = nums[0][0];
        for(int i = 0; i < nums.size(); i++){
            maxi = max(maxi, nums[i][0]);
            pq.push({nums[i][0], i, 0});
        }

        vector<int> ans = {pq.top()[0], maxi};
        int diff = maxi - pq.top()[0];

        while(true){
            auto t = pq.top();
            if(t[2] == nums[t[1]].size() - 1) return ans;

            pq.pop();

            maxi = max(maxi, nums[t[1]][t[2] + 1]);
            pq.push({nums[t[1]][t[2] + 1], t[1], t[2] + 1});

            if(maxi - pq.top()[0] >= diff) continue;

            diff = maxi - pq.top()[0];
            ans = {pq.top()[0], maxi};
        }
    }
};

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

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        auto nums = parse(s);

        print(solution.smallestRange(nums));
    }
    
    return 0;
}