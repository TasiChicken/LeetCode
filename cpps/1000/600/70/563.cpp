#include <bits/stdc++.h>

using namespace std;

class Solution {
    int res;
    int sum_findTilt(TreeNode* node){
        if(!node) return 0;

        int left = sum_findTilt(node->left);
        int right = sum_findTilt(node->right);

        res += abs(left - right);

        return left + right + node->val;
    }
public:
    int findTilt(TreeNode* root) {
        res = 0;

        sum_findTilt(root);

        return res;
    }
};

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

int main() {
    while(true) {
        Solution solution;
        
        string s;
        cin >> s;
        auto root = parse(s);

        cout << solution.findTilt(root) << endl;
    }
    
    return 0;
}