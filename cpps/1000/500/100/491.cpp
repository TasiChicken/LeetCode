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

class Solution {
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& deck, int idx) {
        for (int i = idx; i < nums.size(); i++) {
            if (deck.empty() || nums[i] >= deck.back()) {
                deck.push_back(nums[i]);
                dfs(ans, nums, deck, i + 1);
                deck.pop_back();

                if(deck.size() && nums[i] == deck.back()) return;
            }
        }
        if (deck.size() > 1)
            ans.push_back(deck);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> deck;
        dfs(ans, nums, deck, 0);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);

        print(solution.findSubsequences(nums));
    }
    
    return 0;
}