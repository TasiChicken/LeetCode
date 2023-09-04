#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> parse(string s){
    vector<int> v;
    int last = 1;
    for(int i = 2; i < s.length(); i++)
        if(s[i] == ',' || s[i] == ']') {
            v.push_back(stoi(s.substr(last, i - last)));
            last = i + 1;
        }
    return v;
}

void print(vector<vector<int>> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << "[";
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j];
            if(j != v[i].size() - 1) cout << ",";    
        }
        cout << "]";
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

class Solution {
public:
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> mp;
        int size = nums.size();
        while(size--){
            mp[nums.back()]++;
            nums.pop_back();
        }

        vector<vector<int>> ans;
        ans.push_back(nums);
        size = 1;
        for(auto it = mp.begin(); it != mp.end(); it++){
            for(int i = 0; i < size; i++)
                for(int j = 0; j < it->second; j++){
                    ans.push_back(j ? ans.back() : ans[i]);
                    ans.back().push_back(it->first);
                }
            size *= it->second + 1;
        }
        return ans;
    }
/*Optimized Solution(Maybe)
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        ans.emplace_back(0);

        int size = nums.size(), count = 1, last = 0, num = INT_MIN;
        for(int i = 0; i < size; i++){
            if(nums[i] != num) count = ans.size(), last = 0, num = nums[i];

            for(int j = 0; j < count; j++){
                ans.push_back(ans[last + j]);
                ans.back().push_back(num);
            }
            last += count;
        }
        
        return ans;
    }
*/
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse(s);

        print(solution.subsetsWithDup(nums));
    }
    
    return 0;
}