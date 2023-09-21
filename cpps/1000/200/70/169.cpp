#include <iostream>
#include <vector>

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
    int majorityElement(vector<int>& nums) {
        int left, c = 0;
        for(int n : nums)
            if(!c) left = n, c = 1;
            else c += left == n ? 1 : -1;
        return left;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse(s);

        cout << solution.majorityElement(nums) << endl;
    }
    
    return 0;
}