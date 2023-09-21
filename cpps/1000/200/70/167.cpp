#include <iostream>
#include <vector>

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
    int bs(vector<int>& nums, int l, int r, int tar){
        int m;
        while(l <= r){
            m = l + r >> 1;
            if(nums[m] == tar) return m;
            if(nums[m] > tar) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int r = numbers.size() - 1;
        for(int i = 0, another; ; i++){
            another = target - numbers[i];
            another = bs(numbers, i + 1, r, another);
            if(another != -1) return {i + 1, another + 1};
        }
        return {-1, -1};
    }
/*Optimized Solution
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1, sum;
        while(true){
            sum = numbers[l] + numbers[r]; 
            if(sum == target) return {l + 1, r + 1};
            if(sum > target) r--;
            else l++;
        }
    }
*/
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "numbers = ";
        cin >> s;
        auto numbers = parse(s);
        int target;        
        cout << "target = ";
        cin >> target;

        print(solution.twoSum(numbers, target));
    }
    
    return 0;
}