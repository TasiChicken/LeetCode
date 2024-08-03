#include <iostream>
#include <vector>

using namespace std;

vector<int> parse_(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> maxNums;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j <= maxNums.size(); j++){
                if(j == maxNums.size() || nums[i] > maxNums[j])
                    maxNums.insert(maxNums.begin() + j, nums[i]);
                else if(nums[i] < maxNums[j])
                    continue;
                break;
            }
            if(maxNums.size() > 3) maxNums.pop_back();
        }
        return maxNums.size() == 3 ? maxNums[2] : maxNums[0];
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);

        cout << solution.thirdMax(nums) << endl;
    }
    
    return 0;
}