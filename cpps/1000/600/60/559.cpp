#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;

        int ans = 0;
        for(auto c : root->children)
            ans = max(ans, maxDepth(c));

        return ans + 1;
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}