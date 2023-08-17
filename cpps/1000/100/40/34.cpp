#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int size = nums.size();

        int left = 0, right = size - 1;
        while(left <= right) {
            int mid = (right + left) / 2;
            int num = nums[mid];

            if (num == target) 
                if (mid == 0 || nums[mid - 1] != target){
                    ans[0] = mid;
                    break;
                }
                else right = mid - 1;
            else if (num > target) right = mid - 1;
            else left = mid + 1;
        }

        if(ans[0] == -1) return ans;

        left = ans[0], right = size - 1;
        while(left <= right) {
            int mid = (right + left) / 2;
            int num = nums[mid];

            if (num == target) 
                if (mid == size - 1 || nums[mid + 1] != target){
                    ans[1] = mid;
                    break;
                }
                else left = mid + 1;
            else if (num > target) right = mid - 1;
            else left = mid + 1;
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

        cout << print_output(solution.searchRange(nums, target)) << endl;
    }

    return 0;
}