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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root->val > q->val ^ root->val > p->val) return root;
        if(root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
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