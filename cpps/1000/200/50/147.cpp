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
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *remain = head->next, *pre, *temp;

        head->next = nullptr;
        while(remain){
            temp = remain->next;
            if(remain->val <= head->val){
                remain->next = head;
                head = remain;
                remain = temp;
                continue;
            } 

            pre = head;
            while(pre){
                if(pre->next && remain->val > pre->next->val){
                    pre = pre->next;
                    continue;
                }

                remain->next = pre->next;
                pre->next = remain;
                break;
            }
            remain = temp;
        }
        return head;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "head = ";
        cin >> s;
        auto head = parse(s);

        print(solution.insertionSortList(head));
    }
    
    return 0;
}