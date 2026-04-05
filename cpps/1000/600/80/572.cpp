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
    void serialize(TreeNode* node, string& s){
        if(node == nullptr){
            s += "#,";
            return;
        }

        s += to_string(node->val) + ",";
        serialize(node->left, s);
        serialize(node->right, s);
    }
    vector<int> build_next(string s){
        vector<int> next(s.size());

        int pre_len = 0;
        for(int i = 1; i < s.size(); i++){
            while(pre_len != 0 && s[i] != s[pre_len])
                pre_len = next[pre_len - 1];
            
            if(s[i] == s[pre_len])
                pre_len++;
            next[i] = pre_len;
        }

        return next;
    }
    bool KMP(string a, string b){
        vector<int> next = build_next(b);

        int b_idx = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == b[b_idx]) b_idx++;
            else{
                while(b_idx != 0 && a[i] != b[b_idx])
                    b_idx = next[b_idx - 1];

                if(a[i] == b[b_idx])
                    b_idx++;

            }

            if(b_idx == b.size()) return true;
        }

        return false;   
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string ori = ",", sub = ",";
        serialize(root, ori);
        serialize(subRoot, sub);

        return KMP(ori, sub);
    }
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
        cin >> s;
        auto subRoot = parse(s);

        cout << solution.isSubtree(root, subRoot) << endl;
    }
    
    return 0;
}