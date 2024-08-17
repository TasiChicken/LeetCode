#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    void recursion(vector<vector<int>>& ans, Node* root, int level){
        if(!root) return;
        if(ans.size() < level) ans.emplace_back();

        ans[level - 1].push_back(root->val);
        for(auto child : root->children)
            recursion(ans, child, level + 1);
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        recursion(ans, root, 1);
        return ans;
    }
};