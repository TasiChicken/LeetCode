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

void print(TreeNode* output) {
    cout << '[';
    queue<TreeNode*> q;
    int count = output != nullptr;
    for(q.push(output); count && !q.empty(); q.pop()) {
        if(q.front()){
            cout << q.front()->val;
            q.push(q.front()->left);
            q.push(q.front()->right);

            count = count - 1 + (q.front()->left != nullptr) + (q.front()->right != nullptr);
        }
        else cout << "null";

        if(count) cout << ',';
    }
    cout << ']' << endl;
}

class Solution {
    TreeNode* recursion(TreeNode* node){
        if(!node) return nullptr;
        if(!node->left && !node->right) return node;

        auto l = node->left, r = node->right;
        node->right = l, node->left = nullptr;

        if(l) l = recursion(l), l->right = r;
        else node->right = r;
        if(r) return recursion(r);
        
        return l;
    }
public:
    void flatten(TreeNode* root) {
        recursion(root);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "root = ";
        cin >> s;
        auto root = parse(s);
        solution.flatten(root);

        print(root);
    }
    
    return 0;
}