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
    bool check(vector<pair<int, int>>& _13, int num){
        int l = 0, r = _13.size() - 1;
        while(l <= r){
            int mid = l + r >> 1;
            if(num < _13[mid].first && num > _13[mid].second)
                return true;
            if(num >= _13[mid].first) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
public:
    bool find132pattern(vector<int>& nums) {
        vector<pair<int, int>> _13(1, {nums[0], nums[0]});
        for(int i = 1; i < nums.size(); i++){
            if(check(_13, nums[i])) return true;
            if(nums[i] > nums[i - 1] && nums[i] > _13.back().first){
                _13.back().first = nums[i];
                if(_13.back().first > _13.back().second + 1)
                    while(_13.size() > 1 && nums[i] >= _13[_13.size() - 2].second){
                        _13[_13.size() - 2].second = _13.back().second;
                        _13[_13.size() - 2].first = max(_13[_13.size() - 2].first, _13.back().first);
                        _13.pop_back();
                    }
            }
            else if(nums[i] < nums[i - 1]){
                if(_13.back().first > _13.back().second + 1)
                    _13.push_back({nums[i], nums[i]});
                else _13.back() = {nums[i], nums[i]};
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

        cout << solution.find132pattern(nums) << endl;
    }
    
    return 0;
}