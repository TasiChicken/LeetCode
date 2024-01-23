#include <iostream>
#include <vector>
#include <deque>

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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dp;
        vector<int> ans;
        for(int i = 0; i < k; i++){
            while(!dp.empty() && dp.back() < nums[i]) dp.pop_back();
            dp.push_back(nums[i]);
        }
        ans.push_back(dp.front());
        for(int i = k; i < nums.size(); i++){
            if(dp.front() == nums[i - k]) dp.pop_front();

            while(!dp.empty() && dp.back() < nums[i]) dp.pop_back();
            dp.push_back(nums[i]);
            ans.push_back(dp.front());
        }
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
        int k;
        cout << "k = ";
        cin >> k;

        print(solution.maxSlidingWindow(nums, k));
    }
    
    return 0;
}