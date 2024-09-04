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

void print(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            while(nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] != i + 1)
                ans.push_back(i + 1);
        return ans;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);

        print(solution.findDisappearedNumbers(nums));
    }
    
    return 0;
}