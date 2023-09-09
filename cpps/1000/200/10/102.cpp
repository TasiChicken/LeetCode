#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> level;
        if(root) level.push(root);

        int size;
        while(size = level.size()){
            ans.push_back(vector<int>());
            for(int i = 0; i < size; i++){
                auto node = level.front();
                ans.back().push_back(node->val);

                if(node->left) level.push(node->left);
                if(node->right) level.push(node->right);

                level.pop();        
            }
        }
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