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
    ListNode* merge(ListNode* a, ListNode* b){
        if(!a) return b;
        if(!b) return a;

        if(a->val > b->val) swap(a, b);
        a->next = merge(a->next, b);
        return a;
    }
public:
    ListNode* sortList(ListNode* head){
        if(!head || !head->next) return head;
        auto mid = head, f = head;
        while(f && f->next && f->next->next){
            mid = mid->next;
            f = f->next->next;
        }
        f = mid->next;
        mid->next = nullptr;
        return merge(sortList(head), sortList(f));
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "head = ";
        cin >> s;
        auto head = parse(s);

        print(solution.sortList(head));
    }
    
    return 0;
}