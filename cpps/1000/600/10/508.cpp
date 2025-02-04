#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* parse(string input) {
    TreeNode* head = nullptr;
    input.erase(input.length() - 1, 1);
    input.erase(0, 1);
    
    if(input.length() == 0) return head;

    int index = 0;
    bool left = true;
    queue<TreeNode*> q;
    for(int i = 0; i <= input.length(); i++) 
        if(input[i] == ',' || i == input.length()) {
            auto sub = input.substr(index, i - index);

            TreeNode* node = nullptr;
            if(sub != "null") node = new TreeNode(stoi(input.substr(index, i - index)));
            index = i + 1;

            if(node) q.push(node);
            if(!head){
                head = node;
                continue;
            } 

            if(left) q.front()->left = node;
            else q.front()->right = node, q.pop();
            left = !left;
        }

    return head;
}

void print(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    int tree_sum(unordered_map<int, int>& mp, TreeNode* root){
        if(!root) return 0;
        int ans = tree_sum(mp, root->left) + tree_sum(mp, root->right) + root->val;
        mp[ans]++;
        return ans;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        tree_sum(mp, root);
        
        vector<int> ans;
        int fre = 0;

        for(auto& p : mp)
            if(p.second > fre) ans.clear(), ans.push_back(p.first), fre = p.second;
            else if(p.second == fre) ans.push_back(p.first);
        
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "root = ";
        cin >> s;
        auto root = parse(s);

        print(solution.findFrequentTreeSum(root));
    }
    
    return 0;
}