#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class AllOne {
    struct DLNode{
        unordered_set<string> set;
        DLNode *prev = nullptr, *next = nullptr;
        int val = 0;
    } *tail, *head;
    unordered_map<string, DLNode*> mp;

    void delNode(DLNode* node){
        node->next->prev = node->prev;

        if(node->prev)
            node->prev->next = node->next;
        else
            head = node->next;
    }
    DLNode* insertNodeAfter(DLNode* node){
        DLNode* newNode = new DLNode;
        newNode->next = node->next;
        newNode->next->prev = newNode;
        newNode->prev = node;
        node->next = newNode;
        return newNode;
    }
public:
    AllOne() {
        head = tail = new DLNode;
        tail->set.insert("");
    }
    
    void inc(string key) {
        auto cur = mp.find(key) != mp.end() ? mp[key] : tail;
        cur->set.erase(key);

        if(cur->prev && cur->prev->val == cur->val + 1){
            cur->prev->set.insert(key);
            mp[key] = cur->prev; 
        }
        else{
            mp[key] = cur->prev ? insertNodeAfter(cur->prev) : (head = cur->prev = new DLNode);
            cur->prev->next = cur;
            mp[key]->val = cur->val + 1;
            mp[key]->set.insert(key);
        }

        if(cur->set.empty())
            delNode(cur);
    }    
    
    void dec(string key) {
        auto cur = mp[key];
        cur->set.erase(key);

        if(cur->val == 1)
            mp.erase(key);
        else if(cur->next->val == cur->val - 1){
            cur->next->set.insert(key);
            mp[key] = cur->next; 
        }
        else{
            mp[key] = insertNodeAfter(cur);
            mp[key]->val = cur->val - 1;
            mp[key]->set.insert(key);
        }

        if(cur->set.empty())
            delNode(cur);
    }
    
    string getMaxKey() {
        return *(head->set.begin());
    }
    
    string getMinKey() {
        return head == tail ? "" : *(tail->prev->set.begin());
    }
};