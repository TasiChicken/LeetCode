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
    void recursion(vector<int>& ans, TreeNode* root, int dp = 0){
        if(!root) return;
        if(dp >= ans.size()) ans.push_back(root->val);
        recursion(ans, root->right, dp + 1);
        recursion(ans, root->left, dp + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
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