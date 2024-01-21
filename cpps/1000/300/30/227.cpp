#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void compute(vector<int>& nums, vector<char>& ops, char op){
        int last = nums.size() - 1;
        while(!ops.empty() && (op == '+' || op == '-' || ops.back() == '*' || ops.back() == '/')){
            switch (ops.back())
            {
            case '+':
                nums[last - 1] += nums[last];
                break;
            case '-':
                nums[last - 1] -= nums[last];
                break;
            case '*':
                nums[last - 1] *= nums[last];
                break;
            case '/':
                nums[last - 1] /= nums[last];
                break;
            }
                
            last--;
            ops.pop_back();
            nums.pop_back();
        }            
    }
public:
    int calculate(string s) {
        int num_begin = 0;

        vector<int> nums = { 0 };
        vector<char> ops = { '+' };
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ' || s[i] >= '0' && s[i] <= '9') continue;
            
            nums.push_back(stoi(s.substr(num_begin, i - num_begin)));
            compute(nums, ops, s[i]);
            ops.push_back(s[i]);
            num_begin = i + 1;
        }
        nums.push_back(stoi(s.substr(num_begin)));
        compute(nums, ops, '+');

        return nums[0];
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "s = ";
        getline(cin, s);
        cout << solution.calculate(s) << endl;
    }
    
    return 0;
}