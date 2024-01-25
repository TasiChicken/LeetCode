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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return p ? q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right) : !q;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "p = ";
        cin >> s;
        auto p = parse(s);
        cout << "q = ";
        cin >> s;
        auto q = parse(s);

        cout << solution.isSameTree(p, q) << endl;
    }
    
    return 0;
}