#include <iostream>
#include <vector>
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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        stack<TreeNode*> s[2];
        int sp = 0, size;
        if(root) s[sp].push(root);

        while(size = s[sp].size()){
            ans.push_back(vector<int>());
            for(int i = 0; i < size; i++){
                auto node = s[sp].top();
                ans.back().push_back(node->val);
                
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        stack<TreeNode*> s[2];
        int sp = 0, size;
        if(root) s[sp].push(root);

        while(size = s[sp].size()){
            ans.push_back(vector<int>());
            for(int i = 0; i < size; i++){
                auto node = s[sp].top();
                ans.back().push_back(node->val);
                
                if(sp){
                    if(node->right) s[!sp].push(node->right);
                    if(node->left) s[!sp].push(node->left);
                }
                else{
                    if(node->left) s[!sp].push(node->left);
                    if(node->right) s[!sp].push(node->right);
                }

                s[sp].pop();
            }
            sp = !sp;
        }
        return ans;
    }
};


                s[sp].pop();
            }
            sp = !sp;
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