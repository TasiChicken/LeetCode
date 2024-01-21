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

void print(vector<string> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << '\"' << v[i] << '\"';
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.empty()) return ans;

        int start = nums[0], last = nums.size() - 1;
        for(int i = 0; i < last; i++)
            if(nums[i + 1] != nums[i] + 1){
                ans.push_back(start == nums[i] ? to_string(start) : to_string(start) + "->" + to_string(nums[i]));
                start = nums[i + 1];
            }
        ans.push_back(start == nums[last] ? to_string(start) : to_string(start) + "->" + to_string(nums[last]));

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
        print(solution.summaryRanges(nums));
    }
    
    return 0;
}