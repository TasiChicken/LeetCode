#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int left = 0;
        for(int i = 0; i < len; i++) 
            if(nums[i] != val)
                nums[left++] = nums[i];
        return left + 1;
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

string print_output(vector<int> output) {
    string output_string = "[";
    for(int i = 0; i < output.size(); i++) {
        output_string += to_string(output[i]);
        if(i != output.size() - 1)
            output_string += ",";
    }
    output_string += "]";

    return output_string;
}

int main()
{
    Solution solution;

    while(true) {
        string input;
        vector<int> nums;
        int val;

        cout << "nums = ";
        cin >> input;
        nums = parse_input(input);
        cout << "val = ";
        cin >> val;

        cout << solution.removeElement(nums, val) << ", nums = " << print_output(nums) << endl;
    }
    
    return 0;
}