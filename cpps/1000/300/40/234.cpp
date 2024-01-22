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

class Solution {
    ListNode* reverse(ListNode* head){
        ListNode *prev = nullptr, *cur = head;
        while(cur){
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *half = head, *end = head;
        while (end && end->next){
            half = half->next;
            end = end->next->next;
        }
        
        half = reverse(end ? half->next : half);
        while(half){
            if(half->val != head->val) return false;
            half = half->next;
            head = head->next;
        }

        return true;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "head = ";
        cin >> s;

        cout << solution.isPalindrome(parse(s)) << endl;
    }
    
    return 0;
}