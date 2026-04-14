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
    void preorder(vector<int>& arr, Node* node){
        if(!node) return;
        arr.push_back(node->val);
        for(auto n : node->children)
            preorder(arr, n);
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(res, root);
        return res;
    }
};