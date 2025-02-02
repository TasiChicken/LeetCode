#include <bits/stdc++.h>

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
    int bin_search(vector<int>& nums, int tar, bool dec){
        if(dec && tar >= nums.front() || !dec && tar >= nums.back()) return -1;

        int l = 0, r = nums.size() - 1;
        int& a = (dec ? l : r);
        int& b = (dec ? r : l);
        while(l < r){
            int mid = l + r + dec >> 1;

            if(nums[mid] > tar) a = mid;
            else b = mid + (dec ? -1 : 1);
        }
        return b;
    }
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> inc(1, nums.front()), dec(1, nums.back()) , ans(nums.size(), INT_MIN);
        for(int i = nums.size() - 2; i >= 0; i--){
            int pos = bin_search(dec, nums[i], true);
            if(pos != -1) ans[i] = dec[pos];

            dec.resize(pos + 1);
            dec.push_back(nums[i]);
        }

        if(ans[0] == INT_MIN) ans[0] = -1;
        for(int i = 1; i < nums.size(); i++){
            if(ans[i] == INT_MIN){
                int pos = bin_search(inc, nums[i], false);
                ans[i] = (pos == -1) ? -1 : inc[pos];
            }

            if(nums[i] > inc.back()) inc.push_back(nums[i]);
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

        print(solution.nextGreaterElements(nums));
    }
    
    return 0;
}