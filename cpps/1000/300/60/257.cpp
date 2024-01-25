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

void print(vector<string> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << '\"' << v[i] << '\"';
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    void recursion(vector<string>& ans, string& s, TreeNode* node){
        s += to_string(node->val);

        if(!node->left && !node->right) ans.push_back(s);
        else{
            s += "->";
            if(node->left) recursion(ans, s, node->left);
            if(node->right) recursion(ans, s, node->right);
        }

        do{
            s.pop_back();
        }
        while(!s.empty() && s.back() != '>');
    }   
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        vector<string> ans;
        recursion(ans, s, root);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "root = ";
        cin >> s;
        auto root = parse(s);

        print(solution.binaryTreePaths(root));
    }
    
    return 0;
}