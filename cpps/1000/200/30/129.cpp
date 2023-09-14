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
    void layerCount(TreeNode* node, int& ans, int num){
        num = num * 10 + node->val;

        if(!node->left && !node->right) ans += num;
        if(node->left) layerCount(node->left, ans, num);
        if(node->right) layerCount(node->right, ans, num);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        layerCount(root, ans, 0);
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