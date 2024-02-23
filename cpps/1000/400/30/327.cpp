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

#define ll long long
class Solution {
    vector<ll> preSum, temp;
    int count(int left, int right, int lower, int upper){
        if(left == right) 
            return preSum[left] >= lower && preSum[left] <= upper;

        int mid = left + right >> 1;
        int ans = count(left, mid, lower, upper) + count(mid + 1, right, lower, upper);

        for(int i = mid + 1, l = left, r = l; i <= right && preSum[i] - preSum[mid] <= upper; i++){
            while(l <= mid && preSum[i] - preSum[l] > upper) l++;
            r = max(l, r);
            while(r <= mid && preSum[i] - preSum[r] >= lower) r++;

            ans += r - l;
        }

        for(int i = mid; i >= left; i--)
            temp.push_back(preSum[i]);

        for(int i = left, r = mid + 1; !temp.empty(); i++)
            if(r > right || temp.back() <= preSum[r])
                preSum[i] = temp.back(), temp.pop_back();
            else preSum[i] = preSum[r++];

        return ans;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        preSum.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
            preSum.push_back(preSum[i - 1] + nums[i]);

        return count(0, nums.size() - 1, lower, upper);
    }
};

int main() {
    while(true) {
        Solution solution;
        string s;
        cout << "nums = ";
        cin >> s;
        auto nums = parse_(s);
        int lower;
        cout << "lower = ";
        cin >> lower;
        int upper;
        cout << "upper = ";
        cin >> upper;

        cout << solution.countRangeSum(nums, lower, upper) << endl;
    }
    
    return 0;
}