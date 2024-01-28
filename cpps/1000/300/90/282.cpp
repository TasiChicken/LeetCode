#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<string> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << '\"' << v[i] << '\"';
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

#define ll long long
class Solution {
    const string ops = "*+-";
    void recursion(vector<string>& ans, string& exp, int target, ll a, ll b, ll c, char pre_op, int i){
        if(i == exp.size()){
            if(pre_op == '*') a += b * c;
            else if(pre_op == '+') a += b + c;
            else a += b - c;
            
            if(a == target){
                auto temp = exp;
                temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
                ans.push_back(temp);
            }
            return;
        }

        if(c) exp[i] = ' ', recursion(ans, exp, target, a, b, c * 10 + exp[i + 1] - '0', pre_op, i + 2);
        
        for(auto op : ops){
            exp[i] = op;
            recursion(ans, exp, target, a + b * (pre_op != '*'), (pre_op == '*' ? b : 1) * (pre_op == '-' ? -c : c), exp[i + 1] - '0', exp[i], i + 2);
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string s(num.size() * 2 - 1, ' ');
        for(int i = 0; i < num.size(); i++) s[i << 1] = num[i];
        recursion(ans, s, target, 0, 0, num[0] - '0', '+', 1);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string num;
        cout << "num = ";
        cin >> num;
        int target;
        cout << "target = ";
        cin >> target;

        print(solution.addOperators(num, target));
    }
    
    return 0;
}