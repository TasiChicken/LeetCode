#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1->isLeaf) return (quadTree1->val == 1) ? quadTree1 : quadTree2;
        if(quadTree2->isLeaf) return (quadTree2->val == 1) ? quadTree2 : quadTree1;

        Node* new_node = new Node();
        Node* bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        Node* tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* tr = intersect(quadTree1->topRight, quadTree2->topRight);

        if(bl->isLeaf && br->isLeaf && tl->isLeaf && tr->isLeaf)
            if(bl->val == 1 && br->val == 1 && tl->val == 1 && tr->val == 1){
                new_node->isLeaf = true;
                new_node->val = 1;
                return new_node;
            }
            else if(bl->val == 0 && br->val == 0 && tl->val == 0 && tr->val == 0){
                new_node->isLeaf = true;
                new_node->val = 0;
                return new_node;
            }
        
        new_node->bottomLeft = bl, new_node->bottomRight = br,
        new_node->topLeft = tl, new_node->topRight = tr;

        return new_node;
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}