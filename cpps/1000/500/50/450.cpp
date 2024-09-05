#include <iostream>
#include <queue>
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

void print(vector<TreeNode*> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << '[';
        queue<TreeNode*> q;
        int count = v[i] != nullptr;
        for(q.push(v[i]); count && !q.empty(); q.pop()) {
            if(q.front()){
                cout << q.front()->val;
                q.push(q.front()->left);
                q.push(q.front()->right);

                count = count - 1 + (q.front()->left != nullptr) + (q.front()->right != nullptr);
            }
            else cout << "null";

            if(count) cout << ',';
        }
        cout << ']';
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    int deleteNode(TreeNode* parent, TreeNode* node, bool min){
        if(min){
            if(node->left)
                return deleteNode(node, node->left, true);
            parent->left = node->right;
            return node->val;
        }

        if(node->right)
            return deleteNode(node, node->right, false);
        parent->right = node->left;
        return node->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val < key) root->right = deleteNode(root->right, key);
        else if(root->val > key) root->left = deleteNode(root->left, key);
        // val == key
        else if(root->right){
            if(root->right->left)
                root->val = deleteNode(root, root->right, true);
            else
                root->val = root->right->val, root->right = root->right->right;
        }
        else if(root->left){
            if(root->left->right)
                root->val = deleteNode(root, root->left, false);
            else
                root->val = root->left->val, root->left = root->left->left;
        }
        else return nullptr;
        return root;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "root = ";
        cin >> s;
        auto root = parse(s);
        int key;
        cout << "key = ";
        cin >> key;

        print(solution.deleteNode(root, key));
    }
    
    return 0;
}