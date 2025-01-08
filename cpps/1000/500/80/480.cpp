#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms(nums.begin(), nums.begin() + k);
        vector<double> res;
        
        auto mid = next(ms.begin(), k - 1 >> 1);
        for(int i = k; i <= nums.size(); i++){
            double val = *mid;
            if(~k & 1) val = val / 2 + *(next(mid)) / 2.0;
            res.push_back(val);

            if(i == nums.size()) break;

            ms.insert(nums[i]);

            if(nums[i] < *mid) mid--;
            if(nums[i - k] <= *mid) mid++;

            ms.erase(ms.find(nums[i - k]));
        }

        return res;
    }
};

void print(vector<double> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

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
        auto ans = solution.medianSlidingWindow(nums, k);

        print(ans);
    }
    
    return 0;
}