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
    bool dfs(unordered_set<int>& vals, TreeNode* node, int k){
        if(node == nullptr) return false;
        if(vals.find(k - node->val) != vals.end()) return true;
        vals.insert(node->val);
        return dfs(vals, node->left, k) || dfs(vals, node->right, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> vals;
        return dfs(vals, root, k);
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}