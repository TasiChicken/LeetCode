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
public:
    int minMoves(vector<int>& nums) {
        int m = INT_MAX, ans = 0;
        for(int n : nums)
            m = min(n, m);
        for(int n : nums)
            ans += n - m;
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);

        cout << solution.minMoves(nums) << endl;                
    }
    
    return 0;
}