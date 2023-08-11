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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(0, head);

        ListNode *preTarget = dummyHead;
        ListNode *node = head;
        for(int i = 1; i < n; i++)
            node = node->next;
        while(node->next != NULL){
            node = node->next;
            preTarget = preTarget->next;
        }
        preTarget->next = preTarget->next->next;

        return dummyHead->next;
    }
};

ListNode* parse_input(string input) {
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

string print_output(ListNode* output) {
    string output_string = "[";
    for(; output != NULL; output = output->next) {
        output_string += to_string(output->val);
        if(output->next != nullptr)
            output_string += ",";
    }
    output_string += "]";

    return output_string;
}

int main()
{
    Solution solution;

    while(true) {
        string input;
        ListNode *head;
        int n;

        cout << "head = ";
        cin >> input;
        head = parse_input(input);
        cout << "n = ";
        cin >> n;

        cout << print_output(solution.removeNthFromEnd(head, n)) << endl;
    }
    
    return 0;
}