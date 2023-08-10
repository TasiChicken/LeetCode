#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int, int> mp;

        for(auto num : nums) 
            mp[num] += 1;

        auto it = mp.begin();
        for(; it != mp.end() && it->first < 0; it++) {
            int num = it->first;
            auto nextIt = it->second > 1 ? it : next(it, 1);
            
            for(; nextIt != mp.end(); nextIt++) {
                int target = -num - nextIt->first;
                if(target < nextIt->first) break;

                if(target == nextIt->first ? nextIt->second > 1 : mp[target] > 0)
                    ans.push_back({num, nextIt->first, target});
            }
        }

        if(it->first == 0 && it->second > 2) ans.push_back({0, 0, 0});
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

string print_output(vector<vector<int>> output) {
    string output_string = "[";
    for(int i = 0; i < output.size(); i++) {

        output_string += "[";
        for(int j = 0; j < output[i].size(); j++){
            output_string += to_string(output[i][j]);
            if(j != output[i].size() - 1)
                output_string += ",";
        }
        output_string += "]";

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

        cout << print_output(solution.threeSum(nums)) << endl;
        
    }
    
    return 0;
}
