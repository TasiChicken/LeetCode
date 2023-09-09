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
    TreeNode* recursion(vector<int>& preorder, vector<int>& inorder, int& len, int& pp, int& pi, int* end, stack<int>& higher, int& size){
        while(preorder[pp] != inorder[pi]) higher.push(preorder[pp++]), size++;
        auto node = new TreeNode(inorder[pi]);
        pp++, pi++;

        for(; pi < len && !(end && inorder[pi] == *end);)
            if(size && inorder[pi] == higher.top()) node = new TreeNode(inorder[pi++], node, nullptr), higher.pop(), size--;
            else node->right = recursion(preorder, inorder, len, pp, pi, size ? &(higher.top()) : nullptr, higher, size);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        stack<int> higher;
        int len = preorder.size(), pp = 0, pi = 0, size = 0;
        return recursion(preorder, inorder, len, pp, pi, nullptr, higher, size);
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}