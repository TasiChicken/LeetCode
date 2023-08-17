#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        for(auto i = nums.begin(); i != nums.end(); ) {
            int another = target - *i;
            auto j = find(++i, nums.end(), another);

            if(j != nums.end()) {
                ans.push_back(i - 1 - nums.begin());
                ans.push_back(j - nums.begin());
                break;
            }
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
        int target;

        cout << "nums = ";
        cin >> input;
        nums = parse_input(input);
        cout << "target = ";
        cin >> target;

        cout << print_output(solution.twoSum(nums, target)) << endl;
    }

    return 0;
}