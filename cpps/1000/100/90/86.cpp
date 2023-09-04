#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    void insert(ListNode* a, ListNode* b){
        auto temp = b->next;
        b->next = b->next->next;
        temp->next = a->next;
        a->next = temp;
    }
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0, head);
        head = dummy;
        while(head->next && head->next->val < x) head = head->next;
        
        auto node = head->next;
        if(!node) return dummy->next;
        
        while(node->next){
            while(node->next->val >= x){
                node = node->next;
                if(!node->next) return dummy->next;
            }
            insert(head, node);
            head = head->next;
        }
        return dummy->next;
    }
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


int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "head = ";
        cin >> s;
        auto head = parse(s);
        int x;
        cout << "x = ";
        cin >> x;
        
        print(solution.partition(head, x));
    }
    
    return 0;
}