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
    TreeNode* recursion(vector<int>& inorder, vector<int>& postorder, int& len, int& pi, int& pp, int* end){
        TreeNode* node = nullptr;
        for(; pp < len && (!end || postorder[pp] != *end); pp++){
            node = new TreeNode(inorder[pi], node, 
            recursion(inorder, postorder, len, ++pi, pp, &inorder[pi - 1]));
        }
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pi = 0, pp = 0, len = inorder.size();
        return recursion(inorder, postorder, len, pi, pp, nullptr);
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}