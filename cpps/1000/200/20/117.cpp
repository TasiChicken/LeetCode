
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
    void recursion(Node* node, int& size, vector<Node*>& levels, int level){
        if(!node) return;

        if(size == level) levels.push_back(node), size++;
        else{
            node->next = levels[level];
            levels[level] = node;
        }

        recursion(node->right, size, levels, level + 1);
        recursion(node->left, size, levels, level + 1);
    }
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;

        vector<Node*> levels;
        int size = 0;
        recursion(root->right, size, levels, 0);
        recursion(root->left, size, levels, 0);
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