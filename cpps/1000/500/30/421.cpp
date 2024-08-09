#include <iostream>
#include <vector>

using namespace std;

vector<int> parse_(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}


class Solution {
    struct Node{
        Node* next[2] = {nullptr, nullptr};
        int val = 0;
    } *head;
    void insert(int num){
        auto node = head;
        for(int i = 0; i < 31; i++){
            bool bit = num & (1 << 30 - i);
            if(!node->next[bit]){
                node->next[bit] = new Node();
                node->val |= 1 << bit;
            }
            node = node->next[bit];
        }
    }
    int findmax(Node* a, Node* b, int num){
        if(!a->val) return num;
        
        num <<= 1;
        if(a->val ^ b->val){
            if((a->val & 2) && (b->val & 1))
                return findmax(a->next[1], b->next[0], num + 1);
            return findmax(a->next[0], b->next[1], num + 1);
        }

        if(a->val == 3){
            if(a == b)
                return findmax(a->next[1], b->next[0], num + 1);
            return max(findmax(a->next[1], b->next[0], num + 1), findmax(a->next[0], b->next[1], num + 1));
        }

        if(a->val == 1)        
            return findmax(a->next[0], b->next[0], num);
        return findmax(a->next[1], b->next[1], num);
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        head = new Node();
        for(int num : nums)
            insert(num);
        return findmax(head, head, 0);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);

        cout << solution.findMaximumXOR(nums) << endl;
    }
    
    return 0;
}