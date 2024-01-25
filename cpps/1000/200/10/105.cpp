#include <iostream>
#include <vector>
#include <stack>
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

vector<int> parse_(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
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
    TreeNode* recursion(vector<int>& preorder, vector<int>& inorder, int& len, int& pp, int& pi, int* end, stack<int>& higher, int& size){
        while(preorder[pp] != inorder[pi]) higher.push(preorder[pp++]), size++;
        auto node = new TreeNode(inorder[pi]);
        pp++, pi++;

        for(; pi < len && !(end && inorder[pi] == *end);)
            if(size && inorder[pi] == higher.top()) node = new TreeNode(inorder[pi++], node, nullptr), higher.pop(), size--;
            else node->right = recursion(preorder, inorder, len, pp, pi, size ? &(higher.top()) : nullptr, higher, size);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        stack<int> higher;
        int len = preorder.size(), pp = 0, pi = 0, size = 0;
        return recursion(preorder, inorder, len, pp, pi, nullptr, higher, size);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "preorder = ";
        cin >> s;
        auto preorder = parse_(s);
        cout << "inorder = ";
        cin >> s;
        auto inorder = parse_(s);

        print(solution.buildTree(preorder, inorder));
    }
    
    return 0;
}