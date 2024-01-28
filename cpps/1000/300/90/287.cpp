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
    int findDuplicate(vector<int>& nums) {
        int s = nums[0], f = nums[0];
        do{
            s = nums[s];
            f = nums[nums[f]];
        } while (s != f);

        s = nums[0];
        while (s != f)
            s = nums[s], f = nums[f];

        return s;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);

        cout << solution.findDuplicate(nums) << endl;
    }
    
    return 0;
}