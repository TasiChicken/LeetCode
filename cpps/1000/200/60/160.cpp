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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a = headA, b = headB;
        while(a != b){
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "headA = ";
        cin >> s;
        auto headA = parse(s);
        cout << "headB = ";
        cin >> s;
        auto headB = parse(s);
        
        cout << solution.getIntersectionNode(headA, headB) << endl;
    }
    
    return 0;
}