#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        short size = nums.size(), left = 0, right = size - 1;
        for(int i = 0; i < size; i++){
            while(!nums[left]) left++;
            while(nums[right] == 2) right--;

            if(left > i) i = left;
            if(nums[i] == 2) swap(nums[right--], nums[i]);
            if(nums[i] == 0) swap(nums[left++], nums[i]);
        }
    }
};

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

void print(vector<int> v){
    cout << "[";
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ",";
    }
    cout << "]";
    cout << endl;
}

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse(s);
        solution.sortColors(nums);

        print(nums);
    }
    
    return 0;
}