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
    string dfs(TreeNode* node, unordered_map<string, bool>& mp, vector<TreeNode*>& res){
        if(node == nullptr) return "";
        string hash = to_string(node->val) + "L" + dfs(node->left, mp, res) + 'R' + dfs(node->right, mp, res);
        if(mp.find(hash) != mp.end()){
            if(mp[hash] != true){
                res.push_back(node);
                mp[hash] = true;
            }
        }
        else mp[hash] = false;

        return hash;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, bool> mp;
        vector<TreeNode*> res;
        dfs(root, mp, res);
        return res;
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}