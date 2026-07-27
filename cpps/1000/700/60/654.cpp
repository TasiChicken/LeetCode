#include <bits/stdc++.h>

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> st;
        for(int n : nums){
            TreeNode* node = new TreeNode(n);

            TreeNode* prev = nullptr;
            while(!st.empty() && n > st.back()->val){
                prev = st.back();
                st.pop_back();
            }
            node->left = prev;
            
            if(!st.empty()) st.back()->right = node;
            st.push_back(node);
        }
        
        return st[0];
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}