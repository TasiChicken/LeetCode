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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        while(list1 != NULL && list2 != NULL)
            if(list1->val < list2->val){
                tail = tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail = tail->next = list2;
                list2 = list2->next;
            }
        tail->next = list1 != NULL ? list1 : list2;

        return head->next;
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
        ListNode *l1, *l2;

        cout << "list1 = ";
        cin >> input;
        l1 = parse_input(input);
        cout << "list2 = ";
        cin >> input;
        l2 = parse_input(input);

        cout << print_output(solution.mergeTwoLists(l1, l2)) << endl;
    }
    
    return 0;
}