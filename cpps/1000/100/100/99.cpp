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
    TreeNode* recursion(TreeNode* node, TreeNode* &e1, TreeNode* &e2, int& ptr, TreeNode* next){
        if(!node) return nullptr;
        if(node->right)
            next = recursion(node->right, e1, e2, ptr, next);

        if(next && next->val < node->val){
            if(!e1) e1 = next;
            e2 = node;
        }

        if(node->left)
            return recursion(node->left, e1, e2, ptr, node);
        return node;
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode *e1 = nullptr, *e2 = nullptr;
        int ptr = 0;
        recursion(root, e1, e2, ptr, nullptr);
        swap(e1->val, e2->val);
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}