#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parse(string s){
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
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        string *str = new string[n];
        for(int i = 0 ; i < n; i++) str[i] = to_string(nums[i]);
        sort(str, str + n, [](string& x, string& y){
            return x + y > y + x;
        });
        if(str[0][0] == '0') return "0";
        for(int i = 1; i < n; i++)
            str[0] += str[i];
        return str[0];
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse(s);

        cout << solution.largestNumber(nums) << endl;
    }
    
    return 0;
}