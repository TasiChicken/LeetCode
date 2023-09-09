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
    bool recursion(TreeNode* left, TreeNode* right){
        return left ? right && left->val == right->val && recursion(left->left, right->right) && recursion(left->right, right->left) : !right;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return recursion(root->left, root->right);
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}