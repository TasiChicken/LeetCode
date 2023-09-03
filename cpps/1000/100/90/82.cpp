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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        auto last = head, next = last->next;
        while(true){
            if(next->val != last->val)
                last = last->next = next;
            else if(!next->next){
                last->next = nullptr;
                return head;
            }

            next = next->next;
        }
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
        
        print(solution.deleteDuplicates(head));
    }
    
    return 0;
}