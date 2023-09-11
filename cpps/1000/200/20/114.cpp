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
    TreeNode* recursion(TreeNode* node){
        if(!node) return nullptr;
        if(!node->left && !node->right) return node;

        auto l = node->left, r = node->right;
        node->right = l, node->left = nullptr;

        if(l) l = recursion(l), l->right = r;
        else node->right = r;
        if(r) return recursion(r);
        
        return l;
    }
public:
    void flatten(TreeNode* root) {
        recursion(root);
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}