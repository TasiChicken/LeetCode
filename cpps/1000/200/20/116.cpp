#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
    void recursion(Node* node, int level, vector<Node*>& levels, bool first = true){
        if(first) 
            levels.push_back(node);
        else{
            node->next = levels[level];
            levels[level] = node;
        }

        if(!node->left) return;

        recursion(node->right, level + 1, levels, first);
        recursion(node->left, level + 1, levels, false);
    }
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        vector<Node*> levels;
        recursion(root, 0, levels);
        return root;
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}