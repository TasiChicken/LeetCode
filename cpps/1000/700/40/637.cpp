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
    void rec(TreeNode* node, int lvl, vector<int>& size, vector<double>& sum){
        if(node == nullptr) return;

        if(lvl >= size.size()){
            size.push_back(0);
            sum.push_back(0);
        }

        sum[lvl] += node->val;
        size[lvl]++;

        rec(node->left, lvl + 1, size, sum);
        rec(node->right, lvl + 1, size, sum);        
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> size;
        vector<double> sum;
        rec(root, 0, size, sum);

        for(int i = 0; i < size.size(); i++)
            sum[i] /= size[i];

        return sum;
    }
};