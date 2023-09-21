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

class BSTIterator {
    stack<TreeNode*> s;
    void add(TreeNode* root){
        while(root) s.push(root), root = root->left;
    }
public:
    BSTIterator(TreeNode* root) {
        add(root);
    }
    
    int next() {
        auto n = s.top()->val;
        auto r = s.top()->right;
        s.pop();
        if(r) add(r);
        return n;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};