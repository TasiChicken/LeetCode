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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string& data) {
        int i = 0;
        return deserialize(data, i);
    }

    TreeNode* deserialize(string& data, int& i) {
        if(i >= data.size() || data[i] == '#'){
            i += 2;
            return nullptr;
        }

        int val = 0;
        while(i < data.size() && data[i] != ',')
            val = val * 10 + data[i++] - '0';
        i++;
        TreeNode* node = new TreeNode(val);
        node->left = deserialize(data, i);
        node->right = deserialize(data, i);
        return node;
    }
};

bool thesame(TreeNode* a, TreeNode* b){
    if(!a) return !b;
    return a->val == b->val && thesame(a->left, b->left) && thesame(a->right, b->right);
}

int main(){
    Codec codec;
    string s;
    while(true){
        cout << "root = ";
        cin >> s;
        const auto root = parse(s);

        s = codec.serialize(root);
        auto ans = codec.deserialize(s);
        cout << thesame(root, ans) << endl;
    }
}