#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

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

void print(vector<TreeNode*> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << '[';
        queue<TreeNode*> q;
        int count = v[i] != nullptr;
        for(q.push(v[i]); count && !q.empty(); q.pop()) {
            if(q.front()){
                cout << q.front()->val;
                q.push(q.front()->left);
                q.push(q.front()->right);

                count = count - 1 + (q.front()->left != nullptr) + (q.front()->right != nullptr);
            }
            else cout << "null";

            if(count) cout << ',';
        }
        cout << ']';
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    vector<TreeNode*> recursion(int start, int end, unordered_map<unsigned int, vector<TreeNode*>>& result){
        if(start > end) return { nullptr };
        
        unsigned int key = (start << 16) + end;
        auto f = result.find(key);
        if(f != result.end()) return f->second;

        vector<TreeNode*> ans;
        for(int i = start; i <= end; i++){
            auto left = recursion(start, i - 1, result);
            auto right = recursion(i + 1, end, result);

            for(auto l : left)
                for(auto r : right){
                    auto top = new TreeNode(i);
                    top->left = l, top->right = r;
                    ans.push_back(top);
                }
        }
        return result[key] = ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        unordered_map<unsigned int, vector<TreeNode*>> result;
        return recursion(1, n, result);
    }
};

int main() {
    while(true) {
        Solution solution;
        int n;
        cout << "n = ";
        cin >> n;
        print(solution.generateTrees(n));
    }
    
    return 0;
}