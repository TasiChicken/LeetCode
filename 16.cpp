#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        auto begin = nums.begin(), end = nums.end(), last = end - 1;
        sort(nums.begin(), nums.end());

        int minMargin = INT_MAX;
        int ans;
        for(; begin < last; ++begin) 
            for(auto l = begin + 1, r = last; l < r; ) {
                int total = *begin + *l + *r;
                int margin = abs(target - total);

                if(margin < minMargin) {
                    minMargin = margin;
                    ans = total;
                }

                if(total < target) l++;
                else if(total > target) r--;
                else return total;
            }
            return ans;
    }
};

vector<int> parse_input(string input) {
    vector<int> nums;
    input.erase(input.length() - 1, 1);
    input.erase(0, 1);

    if(input.length() == 0) return nums;

    int index = 0;
    for(int i = 0; i <= input.length(); i++) 
        if(input[i] == ',' || i == input.length()) {
            nums.push_back(stoi(input.substr(index, i - index)));
            index = i + 1;
        }

    return nums;
}

int main()
{
    Solution solution;
    
    while(true) {
        string input;
        vector<int> nums;
        int target;

        cout << "nums = ";
        cin >> input;
        nums = parse_input(input);
        cout << "target = ";
        cin >> target;

        cout << solution.threeSumClosest(nums, target) << endl;
    }

    return 0;
}