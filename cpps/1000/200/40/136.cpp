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
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int n : nums) ans ^= n;
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        auto nums = parse(s);

        cout << solution.singleNumber(nums) << endl;
    }
    
    return 0;
}