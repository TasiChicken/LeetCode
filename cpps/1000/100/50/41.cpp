#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++)
            if(nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]), i--;
        for(int i = 0; i < size;)
            if(nums[i] != ++i) return i;
        return size + 1;
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
        string s;
        cout << "nums = ";
        cin >> s;
        vector<int> nums = parse(s);

        Solution solution;
        cout << solution.firstMissingPositive(nums) << endl;
    }
    
    return 0;
}