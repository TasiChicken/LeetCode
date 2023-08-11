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

        auto _1 = mp.begin();
        for(; _1 != mp.end() && _1->first < 1; _1++) {
            _1->second -= 1;
            for(auto _2 = _1->second > 0 ? _1 : next(_1, 1); _2 != mp.end(); _2++) {
                    long long t = 0ll - _1->first - _2->first;
                    if(t < _2->first) break;
                    if(t < INT_MIN || t > INT_MAX) continue;

                    _2->second -= 1;
                    
                    int last = (int)t;
                    auto result = mp.find(last);
                    if(result != mp.end() && result->second > 0)
                        ans.push_back({_1->first, _2->first, last});

                    _2->second += 1;
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