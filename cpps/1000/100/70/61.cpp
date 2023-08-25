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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k || !head->next) return head;

        int length = 0;
        ListNode *tail, *node;
        for(node = tail = head; ; node = node->next){
            if(k < length) tail = tail->next;
            length++;
            if(!node->next) break;
        }
        if(!(k %= length)) return head;

        node->next = head;
        if(tail != head) node = tail;
        else 
            for(int i = 0; i < length - k; i++)
                node = node->next;

        auto ans = node->next;
        node->next = nullptr;
        return ans;
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
        ListNode* head = parse(s);
        int k;
        cout << "k = ";
        cin >> k;
        print(solution.rotateRight(head, k));
    }
    
    return 0;
}