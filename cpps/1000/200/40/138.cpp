#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    unordered_map<Node*, Node*> mp;
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        auto& ans = mp[head] = new Node(head->val);
        ans->next = copyRandomList(head->next);
        if(head->random) ans->random = mp[head->random];
        return ans;
    }
/*Optimized Solution
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node *node = head, *temp;
        while(node){
            temp = node->next;
            node = node->next = new Node(node->val);
            node = node->next = temp;
        }

        node = head;
        while(node){
            if(node->random) node->next->random = node->random->next;
            node = node->next->next;
        }
        
        temp = head, node = head = head->next;
        while(node){
            temp->next = node->next;
            temp = node;
            node = node->next;
        }

        return head;
    }
*/
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}