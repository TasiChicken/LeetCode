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
    bool increasingTriplet(vector<int>& nums) {
        vector<int> seq;
        seq.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] > seq.back()){
                seq.push_back(nums[i]);
                if(seq.size() >= 3) return true;
            }
            else{
                for(int j = 0; j < seq.size(); j++)
                    if(seq[j] >= nums[i]){
                        seq[j] = nums[i];
                        break;
                    }
            }
        return false;   
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);

        cout << solution.increasingTriplet(nums) << endl;
    }
    
    return 0;
}