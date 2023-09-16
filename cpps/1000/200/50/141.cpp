#include <iostream>
#include <unordered_set>

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

class Solution {
    unordered_set<ListNode*> s;
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        if(s.count(head)) return true;
        s.insert(head);
        return hasCycle(head->next);
    }
/*Optimized Solution
public:
    bool hasCycle(ListNode *head) {
        auto f = head, s = head;
        while(f){
            f = f->next;
            s = s->next;

            if(!f) return false;
            else f = f->next;

            if(f == s) return true;
        }
        return false;
    }
*/
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "head = ";
        cin >> s;
        auto head = parse(s);

        cout << solution.hasCycle(head) << endl;
    }
    
    return 0;
}