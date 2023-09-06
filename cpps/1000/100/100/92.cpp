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

ListNode* parse(string input) {
    ListNode* first;
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

void print(ListNode* output) {
    cout << '[';
    for(; output != NULL; output = output->next) {
        cout << output->val;
        if(output->next != nullptr)
            cout << ',';
    }
    cout << ']' << endl;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        const int len = right - left + 1;
        if(len <= 1) return head;

        vector<int*> nums;
        nums.reserve(len >> 1);
        auto node = head;
        
        while (--left) node = node->next;
        auto s = node;
        for(int i = 0; i < len + 1 >> 1; i++) node = node->next;
        for(int i = 0; i < len >> 1; i++) nums.push_back(&(node->val)), node = node->next;

        for(int i = 0; i < len >> 1; i++) swap(s->val, *(nums[(len >> 1) - 1 - i])), s = s->next;
        return head;
    }
/* Optimized Solution
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int len = right - --left;
        if(len <= 1) return head;

        bool changeH = !left;
        auto node = head;
        ListNode* prev = nullptr;
        if(!changeH){
            while(--left) node = node->next;
            prev = node;
            node = node->next;
        }
        auto last = node, next = node->next;
        node->next = prev;

        while(--len)
            prev = node, node = next, next = node->next, node->next = prev;
        if(!changeH) last->next->next = node;
        last->next = next;
        
        return changeH ? node : head;
    }
*/
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "head = ";
        cin >> s;
        auto head = parse(s);
        int left, right;
        cout << "left = ";
        cin >> left;
        cout << "rightt = ";
        cin >> right;

        print(solution.reverseBetween(head, left, right));
    }
    
    return 0;
}