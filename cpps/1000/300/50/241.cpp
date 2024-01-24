#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
    struct DLNode{
        int val;
        DLNode *next, *pre;
        DLNode(int val = 0, DLNode* pre = nullptr) : val(val), next(nullptr), pre(pre) {
            if(pre) pre->next = this;
        }
    };

    void recursion(vector<int>& ans, DLNode* nums, DLNode* ops){
        if(!ops) ans.push_back(nums->val);

        for(auto op = ops, num = nums; op; op = op->next, num = num->next){
            int a = num->val, b = num->next->val, c, o = op->val;
            if(o == '+') c = a + b;
            else if(o == '-') c = a - b;
            else c = a * b;

            num->next->val = c;
            num->pre->next = num->next;
            if(num->next) num->next->pre = num->pre;
            op->pre->next = op->next;
            if(op->next) op->next->pre = op->pre;

            if(!op->pre->val) recursion(ans, num->next, op->next);
            else recursion(ans, num->pre, op->pre);

            num->next->val = b;
            if(num->next) num->next->pre = num;
            num->pre->next = num;
            if(op->next) op->next->pre = op;
            op->pre->next = op;
        }
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        auto n_head = new DLNode(), n = n_head, o_head = new DLNode(), o = o_head;
        
        int last = 0;
        for(int i = 0; i < expression.size(); i++)
            if(expression[i] < '0' || expression[i] > '9'){
                n = new DLNode(stoi(expression.substr(last, i - last)), n);                
                o = new DLNode(expression[i], o);
                last = i + 1;
            }
        n = new DLNode(stoi(expression.substr(last)), n);
        
        vector<int> ans;
        recursion(ans, n_head->next, o_head->next);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string expression;
        cout << "expression = ";
        cin >> expression;
        print(solution.diffWaysToCompute(expression));
    }
    
    return 0;
}