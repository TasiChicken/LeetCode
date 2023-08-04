#include <iostream>
#include <cstring>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node = new ListNode(0);
        addTwoNumbers(l1, l2, node);
        return node;
    }
private:
    void addTwoNumbers(ListNode* l1, ListNode* l2, ListNode*& node) {
        if(l1 == nullptr && l2 == nullptr) return;

        if(l1 != nullptr) {
            node->val += l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr) {
            node->val += l2->val;
            l2 = l2->next;
        }

        if(node->val >= 10) {
            node->val -= 10;
            node->next = new ListNode(1);
        }
        else if (l1 != nullptr || l2 != nullptr)
            node->next = new ListNode();

        addTwoNumbers(l1, l2, node->next);
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

        cout << "l1 = ";
        cin >> input;
        l1 = parse_input(input);
        cout << "l2 = ";
        cin >> input;
        l2 = parse_input(input);

        cout << print_output(solution.addTwoNumbers(l1, l2)) << endl;
    }
    return 0;
}
