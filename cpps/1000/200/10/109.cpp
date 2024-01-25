#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* parse(string input) {
    ListNode* first = nullptr;
    input.erase(input.length() - 1, 1);
    input.erase(0, 1);
    
    if(input.length() == 0) return first;

    int index = 0;
    ListNode* last;
    for(int i = 0; i <= input.length(); i++) 
        if(input[i] == ',' || i == input.length()) {
            int value = stoi(input.substr(index, i - index));

            if(index == 0) first = last = new ListNode(value);
            else {
                last->next = new ListNode(value);
                last = last->next;
            }
            index = i + 1;
        }

    return first;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print(TreeNode* output) {
    cout << '[';
    queue<TreeNode*> q;
    int count = output != nullptr;
    for(q.push(output); count && !q.empty(); q.pop()) {
        if(q.front()){
            cout << q.front()->val;
            q.push(q.front()->left);
            q.push(q.front()->right);

            count = count - 1 + (q.front()->left != nullptr) + (q.front()->right != nullptr);
        }
        else cout << "null";

        if(count) cout << ',';
    }
    cout << ']' << endl;
}

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
        string s;
        cout << "head = ";
        cin >> s;
        auto head = parse(s);

        print(solution.sortedListToBST(head));
    }
    
    return 0;
}