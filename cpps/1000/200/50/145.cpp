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
        recursion(ans, node->left);
        recursion(ans, node->right);
        ans.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
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