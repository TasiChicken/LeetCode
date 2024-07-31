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
    bool check(vector<int>& nums, int upper, int k){
        int num = 0;
        for(int i = 0; i < nums.size(); i++)
            if((num += nums[i]) > upper){
                num = nums[i];
                if(num > upper || --k <= 0) return false;
            }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int sum = 0, biggest = 0;
        for(int n : nums)
            sum += n, biggest = max(biggest, n);
        int l = max(sum / k, biggest), r = sum;
        while(l < r){
            int mid = l + r >> 1;
            if(check(nums, mid, k))
                r = mid;
            else l = mid + 1;
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
        auto nums = parse_(s);
        int k;
        cout << "k = ";
        cin >> k;

        cout << solution.splitArray(nums, k) << endl;
    }
    
    return 0;
}