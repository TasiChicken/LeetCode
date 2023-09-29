#include <iostream>

using namespace std;

class Trie {
    struct Node{
    public:
        Node *left = nullptr, *right = nullptr;
        string val;
        Node(string val){ this->val = val; }
    };

    int compare(string &a, string &b){
        int la = a.length(), lb = b.length();
        for(int i = 0; i < la && i < lb; i++)
            if(a[i] != b[i]) return a[i] > b[i] ? 2 : -2;
        return la < lb ? -1 : la > lb;        
    }

    void insert(Node* &n, string &s){
        if(!n) n = new Node(s);
        else insert(compare(n->val, s) > 0 ? n->left : n->right, s);
    }

    bool search(Node* n, string &s){
        if(!n) return false;
        int r = compare(n->val, s);
        return r ? search(r > 0 ? n->left : n->right, s) : true;
    }
    
    bool startsWith(Node* n, string &s){
        if(!n) return false;
        int r = compare(n->val, s);
        return r && r != 1 ? startsWith(r > 0 ? n->left : n->right, s) : true;
    }
public:
    Node* head = nullptr;
    Trie() {
        
    }
    
    void insert(string word) {
        insert(head, word);
    }
    
    bool search(string word) {
        return search(head, word);
    }
    
    bool startsWith(string prefix) {
        return startsWith(head, prefix);
    }
};