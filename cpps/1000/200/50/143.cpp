#include <iostream>

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
    ListNode* reverse(ListNode* node){
        ListNode *left = node, *n;
        while(node->next){
            n = node->next;
            node->next = n->next;
            n->next = left;
            left = n;
        }
        return left;
    }
public:
    void reorderList(ListNode* head) {
        auto mid = head, node = head;
        while(node && node->next){
            node = node->next->next;
            mid = mid->next;
        }
        if(!mid->next) return;

        mid = reverse(mid);
        while(head){
            node = head->next;
            head = head->next = mid;
            mid = node;
        }
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "head = ";
        cin >> s;
        auto head = parse(s);
        solution.reorderList(head);

        print(head);
    }
    
    return 0;
}