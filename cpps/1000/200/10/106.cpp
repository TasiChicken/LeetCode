#include <iostream>
#include <vector>
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
    TreeNode* recursion(vector<int>& inorder, vector<int>& postorder, int& len, int& pi, int& pp, int* end){
        TreeNode* node = nullptr;
        for(; pp < len && (!end || postorder[pp] != *end); pp++){
            int num = inorder[pi++];
            node = new TreeNode(num, node, recursion(inorder, postorder, len, pi, pp, &inorder[pi - 1]));
        }
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pi = 0, pp = 0, len = inorder.size();
        return recursion(inorder, postorder, len, pi, pp, nullptr);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "inorder = ";
        cin >> s;
        auto inorder = parse_(s);
        cout << "postorder = ";
        cin >> s;
        auto postorder = parse_(s);

        print(solution.buildTree(inorder, postorder));
    }
    
    return 0;
}