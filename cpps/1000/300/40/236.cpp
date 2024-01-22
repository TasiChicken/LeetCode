#include <iostream>
#include <vector>

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
    bool findPos(TreeNode* root, TreeNode* n, vector<bool>& s){
        if(root == n) return true;
        if(root->left) {
            s.push_back(false);
            if(findPos(root->left, n, s)) return true;
            s.pop_back();
        }
        if(root->right) {
            s.push_back(true);
            if(findPos(root->right, n, s)) return true;
            s.pop_back();
        }
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<bool> qPos, pPos;
        findPos(root, q, qPos);
        findPos(root, p, pPos);

        int size = min(pPos.size(), qPos.size());
        for(int i = 0; i < size && pPos[i] == qPos[i]; i++)
            root = pPos[i] ? root->right : root->left;
        return root;
    }
/*Optimized Solution
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q), *r = lowestCommonAncestor(root->right, p, q);
        return l ? (r ? root : l) : r;
    }
*/
};