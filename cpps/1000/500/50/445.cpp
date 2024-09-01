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
    void rever(ListNode* l){
        while(l->next)
            swap(l->val, l->next->val), l = l->next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        rever(l1);
        rever(l2);

        auto temp1 = l1, temp2 = l2;
        while(temp1){
            if(!temp1->next && temp2 && temp2->next)
                temp1->next = temp2->next;
            temp1->val += temp2 ? temp2->val : 0;
            if(temp1->val > 9){
                temp1->val -= 10;
                if(!temp1->next) temp1->next = new ListNode;
                temp1->next->val += 1;
            }

            temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }

        rever(l1);
        return l1;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "l1 = ";
        cin >> s;
        auto l1 = parse(s);
        cout << "l2 = ";
        cin >> s;
        auto l2 = parse(s);

        print(solution.addTwoNumbers(l1, l2));
    }
    
    return 0;
}