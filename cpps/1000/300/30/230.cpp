#include <iostream>
#include <stack>

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> tops;
        int index = 0;
        
        while(root){
            while(root){
                tops.push(root);
                root = root->left;
            }

            while(!root && !tops.empty()) {
                root = tops.top();
                
                if(++index == k) return root->val;
                tops.pop();
                root = root->right;
            }
        }

        return -1;
    }
};