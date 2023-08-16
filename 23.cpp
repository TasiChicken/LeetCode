#include <iostream>
#include <vector>
#include <algorithm>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(0);
        recursion(lists, head);
        return head->next;
    }
private:
    void recursion(vector<ListNode*>& lists, ListNode* head) {
        lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());
        int size = lists.size();

        if(size == 0) return;

        int min = lists[0]->val;
        int index = 0;
        for(int i = 1; i < size; i++) 
            if(lists[i]->val < min) {
                min = lists[i]->val;
                index = i;
            }

        ListNode* node = lists[index];            
        head->next = node;
        lists[index] = node->next;
        recursion(lists, node);
    }
/* Optimized Solution
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size == 0) return NULL;
        ListNode* head = lists[0];
        for(int i = 1; i < size; i++)
            head = mergeTwoLists(head, lists[i]);
        return head;
    }
private:
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
*/
};

ListNode* parse_lists(string input) {
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

vector<ListNode*> parse_input(string input) {
    vector<ListNode*> lists;
    input.erase(input.length() - 1, 1);
    input.erase(0, 1);

    if(input.length() == 0) return lists;
    
    bool inside = true;
    int index = 0;
    for(int i = 0; i <= input.length(); i++) 
        if(input[i] == '[') inside = true;
        else if(input[i] == ']') inside = false;
        else if(!inside && input[i] == ',' || i == input.length()) {
            lists.push_back(parse_lists(input.substr(index, i - index)));
            index = i + 1;
        }

    return lists;
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
        vector<ListNode*> lists;

        cout << "lists = ";
        cin >> input;
        lists = parse_input(input);

        cout << print_output(solution.mergeKLists(lists)) << endl;
    }
    
    return 0;
}