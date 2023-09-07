#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
        //code here
    }
    
    return 0;
}