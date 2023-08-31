#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size(), left;
        bool duplicated = false;
        
        for(left = 1; left < size; left++)
            if(nums[left] != nums[left - 1]) duplicated = false;
            else if (duplicated) break;
            else duplicated = true;
        for(int right = left + 1; right < size; right++)
            if(nums[right] != nums[left - 1]) nums[left++] = nums[right], duplicated = false;
            else if(!duplicated) nums[left++] = nums[right], duplicated = true;
        return left;
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
        auto nums = parse(s);
        
        cout << solution.removeDuplicates(nums) << endl;
    }
    
    return 0;
}