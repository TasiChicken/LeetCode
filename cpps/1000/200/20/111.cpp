#include <iostream>
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int d = 0, size;
        if(root) q.push(root);
        while(size = q.size()){
            d++;
            while(size--){
                auto n = q.front();
                q.pop();
                bool leaf = false;
                if(n->left) q.push(n->left), leaf = true;
                if(n->right) q.push(n->right), leaf = true;
                if(!leaf) return d;
            }
        }
        return d;
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}