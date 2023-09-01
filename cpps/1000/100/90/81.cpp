#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size(), left = 0, right = size - 2, mid, first = nums[0];
        if(target == first || target == nums.back()) return true;
        while (++left < size && nums[left] == first);
        
        bool inRo = target > first;
        while(left <= right){
            mid = left + right >> 1;
            if(nums[mid] == target) return true;

            bool tooBig = nums[mid] > target, corSeg = nums[mid] <= first;
            if(inRo ? tooBig || corSeg : tooBig && corSeg) right = mid - 1;
            else left = mid + 1;
        }
        return false;
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
        int target;
        cout << "target = ";
        cin >> target;

        cout << solution.search(nums, target) << endl;
    }
    
    return 0;
}