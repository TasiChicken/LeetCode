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
    void recursion(vector<int>& ans, TreeNode* node){
        if(!node) return;
        ans.push_back(node->val);
        recursion(ans, node->left);
        recursion(ans, node->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        recursion(ans, root);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}