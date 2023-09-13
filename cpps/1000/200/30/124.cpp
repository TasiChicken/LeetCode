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
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return INT_MIN;
        int dl = maxPathSum(root->left) , dr = maxPathSum(root->right);
        int sl = root->left ? root->left->val : 0 , sr = root->right ? root->right->val : 0;
        root->val += max(0, max(sl, sr));
        return max(root->val + max(0, min(sl, sr)), max(dl, dr));
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}