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
    int get_h(TreeNode* node, int h){
        if(node == nullptr) return h - 1;
        return max(get_h(node->left, h + 1), get_h(node->right, h + 1));
    }
    void fill_res(vector<vector<string>>& res, int r, int c, int h, TreeNode* node){
        if(node == nullptr) return;

        res[r][c] = to_string(node->val);

        if(h - r - 1 < 0) return;
        fill_res(res, r + 1, c - (1 << h - r - 1), h, node->left);
        fill_res(res, r + 1, c + (1 << h - r - 1), h, node->right);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = get_h(root, 0);
        int m = h + 1;
        int n = (1 << h + 1) - 1;
        vector<vector<string>> res = vector<vector<string>>(m, vector<string>(n));
        fill_res(res, 0, (n - 1) / 2, h, root);
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