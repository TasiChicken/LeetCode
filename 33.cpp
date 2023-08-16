#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0) return -1;

        int first = nums[0];
        bool inRotated = target >= first;

        int left = 0, right = size - 1;
        while(left <= right) {
            int center = (left + right) / 2;
            int num = nums[center];
            if(num == target) return center;

            bool tooBig = num > target, oriSeg = num < first;
            //if(inRotated && tooBig || inRotated && oriSeg || tooBig && oriSeg) right = center - 1;
            if(inRotated ? tooBig || oriSeg : tooBig && oriSeg) right = center - 1;
            else left = center + 1;
        }
        return -1;
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

        cout << solution.search(nums, target) << endl;
    }
    
    return 0;
}