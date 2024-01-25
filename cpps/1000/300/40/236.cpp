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

TreeNode* parse(string input) {
    TreeNode* head = nullptr;
    input.erase(input.length() - 1, 1);
    input.erase(0, 1);
    
    if(input.length() == 0) return head;

    int index = 0;
    bool left = true;
    queue<TreeNode*> q;
    for(int i = 0; i <= input.length(); i++) 
        if(input[i] == ',' || i == input.length()) {
            auto sub = input.substr(index, i - index);

            TreeNode* node = nullptr;
            if(sub != "null") node = new TreeNode(stoi(input.substr(index, i - index)));
            index = i + 1;

            if(node) q.push(node);
            if(!head){
                head = node;
                continue;
            } 

            if(left) q.front()->left = node;
            else q.front()->right = node, q.pop();
            left = !left;
        }

    return head;
}

class Solution {
    bool findPos(TreeNode* root, TreeNode* n, vector<bool>& s){
        if(root == n) return true;
        if(root->left) {
            s.push_back(false);
            if(findPos(root->left, n, s)) return true;
            s.pop_back();
        }
        if(root->right) {
            s.push_back(true);
            if(findPos(root->right, n, s)) return true;
            s.pop_back();
        }
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<bool> qPos, pPos;
        findPos(root, q, qPos);
        findPos(root, p, pPos);

        int size = min(pPos.size(), qPos.size());
        for(int i = 0; i < size && pPos[i] == qPos[i]; i++)
            root = pPos[i] ? root->right : root->left;
        return root;
    }
/*Optimized Solution
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q), *r = lowestCommonAncestor(root->right, p, q);
        return l ? (r ? root : l) : r;
    }
*/
};

TreeNode* find(TreeNode* node, int n){
    if(!node) return nullptr;
    if(node->val == n) return node;
    auto left = find(node->left, n);
    return left ? left : find(node->right, n);
}

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "root = ";
        cin >> s;
        auto root = parse(s);
        int n;
        cout << "p = ";
        cin >> n;
        auto p = find(root, n);
        cout << "q = ";
        cin >> n;
        auto q = find(root, n);

        cout << solution.lowestCommonAncestor(root, p, q)->val << endl;
    }
    
    return 0;
}