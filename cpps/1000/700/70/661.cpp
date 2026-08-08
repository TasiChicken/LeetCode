#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void fill_w(vector<pair<unsigned int, unsigned int>>& w, TreeNode* node, unsigned int cur_d, unsigned int cur_w){
        if(node == nullptr) return;

        if(cur_d == w.size()) w.emplace_back(cur_w, cur_w);
        else{
            w[cur_d].first = min(w[cur_d].first, cur_w);
            w[cur_d].second = max(w[cur_d].second, cur_w);
        }

        fill_w(w, node->left, cur_d + 1, cur_w * 2);
        fill_w(w, node->right, cur_d + 1, cur_w * 2 + 1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<unsigned int, unsigned int>> w;
        fill_w(w, root, 0, 0);

        unsigned int res = 0;
        for(const auto& ww : w)
            res = max(res, ww.second - ww.first + 1);

        return res;
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}