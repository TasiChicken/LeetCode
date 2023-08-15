#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto end = nums.end(), begin = nums.begin();
        for(auto it = end - 1; it != begin;) {
            auto last = it - 1;
            if(*last < *it) {
                auto sortStart = it;

                do it++;
                while(it != nums.end() && *it > *last);

                swap(*last, *--it);
                sort(sortStart, end);

                return;
            }
            it = last;
        }

        sort(begin, end);
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

        cout << "nums = ";
        cin >> input;
        nums = parse_input(input);
        solution.nextPermutation(nums);

        cout << print_output(nums) << endl;
    }
    
    return 0;
}