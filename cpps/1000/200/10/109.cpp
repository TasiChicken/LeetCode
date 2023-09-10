#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode* end = nullptr) {
        if(head == end) return nullptr;
        auto m = head, f = head;
        while(f->next != end && f->next->next != end)
            f = f->next->next, m = m->next;
        return new TreeNode(m->val, sortedListToBST(head, m), sortedListToBST(m->next, end));
    }
};

int main() {
    while(true) {
        Solution solution;
        //code here
    }
    
    return 0;
}