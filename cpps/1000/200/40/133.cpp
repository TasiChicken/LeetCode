#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    unordered_map<int, Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(mp[node->val] != nullptr) return mp[node->val];

        mp[node->val] = node = new Node(node->val, node->neighbors);
        for(int i = 0; i < node->neighbors.size(); i++)
            node->neighbors[i] = cloneGraph(node->neighbors[i]);
        return node;
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}