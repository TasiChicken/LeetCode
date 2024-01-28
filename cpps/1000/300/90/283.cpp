#include <iostream>
#include <vector>
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
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), zp = 0;
        // find the first zero
        while(zp < n && nums[zp]) zp++;
        // if no zero
        if(zp == n) return;

        for(int i = zp + 1; i < n && zp < i; i++){
            // to the next nonzero element
            while(i < n && !nums[i]) i++;
            if(i == n) return;

            swap(nums[zp++], nums[i]);

            // find the next zero
            while(zp < i && nums[zp]) zp++;
        }

    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);
        solution.moveZeroes(nums);

        print(nums);
    }
    
    return 0;
}