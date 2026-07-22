#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct TreeNode{
        vector<TreeNode*> children;
        bool is_root;
        TreeNode() : is_root(false), children(vector<TreeNode*>(26, nullptr)) {}
    } *root;
    void build_tree(const string& s){
        TreeNode* node = root;
        for(char c : s){
            if(node->children[c - 'a'] == nullptr)
                node->children[c - 'a'] = new TreeNode();
            
            node = node->children[c - 'a'];
        }
        node->is_root = true;
    }
    string find_root(string& s){
        TreeNode* node = root;
        for(int i = 0; i < s.size(); i++){
            if(node->children[s[i] - 'a'] == nullptr)
                return s;
            
            node = node->children[s[i] - 'a'];
            if(node->is_root) return s.substr(0, i + 1);
        }

        return s;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TreeNode();
        for(string& s : dictionary)
            build_tree(s);

        istringstream ss(sentence);
        ostringstream out;

        string word;
        while(ss >> word){
            out << find_root(word);
            out << ' ';
        }

        auto res = out.str();
        res.pop_back();
        return res;
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}