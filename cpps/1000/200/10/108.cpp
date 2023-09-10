#include <iostream>
#include <vector>

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
    TreeNode* recursion(vector<int>& nums, int start, int end){
        if(start >= end) return nullptr;
        int m = start + end >> 1;
        return new TreeNode(nums[m], recursion(nums, start, m), recursion(nums, m + 1, end));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursion(nums, 0, nums.size());
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}