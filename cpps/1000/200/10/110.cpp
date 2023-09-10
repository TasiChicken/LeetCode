#include <iostream>

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
    int depth(TreeNode* root){
        if(!root) return 0;
        int l = depth(root->left), r = depth(root->right);
        if(l < r) swap(l, r);
        
        if(l == INT_MAX || l - r > 1) return INT_MAX;
        return l + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) != INT_MAX;
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}