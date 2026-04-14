#include <bits/stdc++.h>

using namespace std;

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
    void postorder(vector<int>& arr, Node* node){
        if(!node) return;
        for(auto n : node->children)
            postorder(arr, n);
        arr.push_back(node->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(res, root);
        return res;
    }
};