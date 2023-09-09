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
    bool isValidBST(TreeNode* root, int* min = nullptr, int* max = nullptr) {
        if(!root) return true;
        return (!min || root->val > *min) && (!max || root->val < *max)
        && isValidBST(root->left, min, &(root->val))
        && isValidBST(root->right, &(root->val), max);
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}