#include <iostream>
#include <vector>;

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums, int index = 0, int start = 1, int last = INT_MIN) {
        if(last == INT_MIN) last = nums.size() - 1;

        int dis = last - index;
        if(dis <= 0) return 0;
        if(dis <= nums[index]) return 1;

        int maxDelta = 0;
        for(int i = start; i <= nums[index]; i++)
            if(i + nums[index + i] > maxDelta + nums[index + maxDelta]) maxDelta = i;
        return 1 + jump(nums, index + maxDelta, nums[index] - maxDelta, last);
    }
};

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

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        vector<int> nums = parse(s);

        cout << solution.jump(nums) << endl;
    }
    
    return 0;
}