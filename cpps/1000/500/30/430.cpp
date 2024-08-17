#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* node = head;
        vector<Node*> tails;
        while(node)
            if(node->child){
                if(node->next)
                    tails.push_back(node->next);
                node->child->prev = node;
                node->next = node->child;
                node->child = nullptr;
                node = node->next;
            }
            else if(node->next)
                node = node->next;
            else if(!tails.empty()){
                tails.back()->prev = node;
                node = node->next = tails.back();
                tails.pop_back();
            }
            else break;
        return head;
    }
};