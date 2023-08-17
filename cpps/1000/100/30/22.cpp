#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recursion(ans, "", 0, 0, n);
        return ans;
    }
private:
    void recursion(vector<string>& ans, string s, int left, int right, int n) {
        if(left == n && right == n) return ans.push_back(s);

        if(left < n) recursion(ans, s + "(", left + 1, right, n);
        if(right < left) recursion(ans, s + ")", left, right + 1, n);
    }
};

string print_output(vector<string> output) {
    string output_string = "[";
    for(int i = 0; i < output.size(); i++) {
        output_string += "\"" + output[i] + "\"";
        if(i != output.size() - 1)
            output_string += ",";
    }
    output_string += "]";

    return output_string;
}

int main()
{
    Solution solution;

    while(true) {
        int n;
        cout << "n = ";
        cin >> n;
        cout << print_output(solution.generateParenthesis(n)) << endl;
    }
    
    return 0;
}