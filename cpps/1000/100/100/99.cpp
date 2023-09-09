#include <iostream>
#include <vector>
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

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int l = 0, r = nums[size - 1] - nums[0], m, counter;
        while(l <= r){
            m = (l + r) >> 1, counter = 0;
            for(int i = 1; i < size && counter < p; i++)
                if(nums[i] - nums[i - 1] <= m){
                    i++, counter++;
                }
            if(counter < p) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse(s);
        int p;
        cout << "p = ";
        cin >> p;

        cout << solution.minimizeMax(nums, p) << endl;
    }
    
    return 0;
}