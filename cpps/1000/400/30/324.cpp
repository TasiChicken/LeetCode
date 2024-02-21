#include <iostream>
#include <vector>
#include <algorithm>

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
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        nth_element(nums.begin(), nums.begin() + size / 2, nums.end());
        int median = nums[size / 2];

        for(int i = 1, j = size + 1 >> 1; i < size && j < size; i += 2)
            swap(nums[i], nums[j++]);

        for(int i = 0, j = size - 2 + size % 2; ; i += 2, j -= 2){
            while(i < j && nums[i] == median) i += 2;
            while(i < j && nums[j] != median) j -= 2;
            if(i >= j) break;
            swap(nums[i], nums[j]);
        }

        for(int i = 1, j = size - 1 - size % 2; ; i += 2, j -= 2){
            while(i < j && nums[i] != median) i += 2;
            while(i < j && nums[j] == median) j -= 2;
            if(i >= j) break;
            swap(nums[i], nums[j]);
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
        solution.wiggleSort(nums);

        print(nums);
    }
    
    return 0;
}