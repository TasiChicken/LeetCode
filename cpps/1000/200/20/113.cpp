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
    void recursion(vector<vector<int>>& ans, vector<int>& v, TreeNode* root, int targetSum){
        if(!root) return;

        targetSum -= root->val;
        v.push_back(root->val);
        if(!targetSum && !root->left && !root->right) ans.push_back(v);
        recursion(ans, v, root->left, targetSum);
        recursion(ans, v, root->right, targetSum);
        v.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        recursion(ans, v, root, targetSum);
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