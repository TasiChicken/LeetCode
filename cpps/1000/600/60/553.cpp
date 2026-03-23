#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct Node{
        float val = 0;
        int pos;
    };
    
    vector<vector<Node>> max_dp, min_dp;
    float findMax(vector<int>& nums, int from, int to){
        auto& node = max_dp[from][to];
        if(node.val) return node.val;

        for(int i = from; i < to; i++){
            float div = findMax(nums, from, i) / findMin(nums, i + 1, to);
            if(i == from || div > node.val)
                node.val = div, node.pos = i;
        }

        return node.val;
    }
    float findMin(vector<int>& nums, int from, int to){
        auto& node = min_dp[from][to];
        if(node.val) return node.val;

        for(int i = from; i < to; i++){
            float div = findMin(nums, from, i) / findMax(nums, i + 1, to);
            if(i == from || div < node.val)
                node.val = div, node.pos = i;
        }

        return node.val;
    }
    string max2string(vector<int>& nums, int from, int to){
        if(to == from) return to_string(nums[from]);

        auto& node = max_dp[from][to];
        string s = max2string(nums, from, node.pos);
        s += "/";
        if(to - (node.pos + 1) > 0) s += "(";
        s += min2string(nums, node.pos + 1, to);
        if(to - (node.pos + 1) > 0) s += ")";
        return s;
    }
    string min2string(vector<int>& nums, int from, int to){
        if(to == from) return to_string(nums[from]);

        auto& node = min_dp[from][to];
        string s = min2string(nums, from, node.pos);
        s += "/";
        if(to - (node.pos + 1) > 0) s += "(";
        s += max2string(nums, node.pos + 1, to);
        if(to - (node.pos + 1) > 0) s += ")";
        return s;
    }
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return to_string(nums[0]);

        max_dp = vector<vector<Node>>(n, vector<Node>(n));
        min_dp = vector<vector<Node>>(n, vector<Node>(n));

        for(int i = 0; i < n; i++)
            max_dp[i][i].val = min_dp[i][i].val = nums[i];

        findMax(nums, 0, n - 1);

        return max2string(nums, 0, n - 1);
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

int main() {
    while(true) {
        Solution solution;
        string s;
        cin >> s;
        auto nums = parse_(s);
        cout << solution.optimalDivision(nums) << endl;
    }
    
    return 0;
}