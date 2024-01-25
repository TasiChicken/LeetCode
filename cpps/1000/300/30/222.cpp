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

class Solution {
    int depth(TreeNode* root, bool isleft){
        if(!root) return 0;
        return 1 + depth(isleft ? root->left : root->right, isleft);
    }
    bool exist(TreeNode* root, int index){
        int bit = 16;
        while(!(index & (1 << bit--)));

        for(int i = bit; i >= 0; i--)
            root = (index & (1 << i)) ? root->right : root->left;
        return root;
    }
public:
    int countNodes(TreeNode* root) {
        int l = depth(root, true), r = depth(root, false);
        if(l == r) return (1 << l) - 1;

        int minAns = 1 << r, maxAns = (1 << l) - 2, mid;
        while(minAns < maxAns){
            mid = minAns + maxAns >> 1;
            if(exist(root, mid)) minAns = mid + 1;
            else maxAns = mid - 1;
        }
        return maxAns - !exist(root, maxAns);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "root = ";
        cin >> s;
        auto root = parse(s);

        cout << solution.countNodes(root) << endl;
    }
    
    return 0;
}