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

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, s = nums.size(), ans = 0, sum = 0;
        while(r < s && ans != 1){
            sum += nums[r++];
            while(sum >= target) {
                if(r - l < ans || !ans) ans = r - l;
                sum -= nums[l++];
            }
        }
        return ans;
    }
/* Another Solution
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums[0] > target) return 1;

        int s = nums.size(), ans = INT_MAX;
        for(int i = 1; i < s; i++){
            if(nums[i] > target) return 1;

            nums[i] += nums[i - 1];
            if(nums[i] < target) continue;
            if(nums[i] - nums[0] < target){
                ans = min(ans, i + 1);
                continue;
            }

            int l = 1, r = i, mid;
            while(l < r){
                mid = l + r >> 1;
                if(nums[i] - nums[mid] < target)
                    if(nums[i] - nums[mid - 1] >= target) l = r = mid;
                    else r = mid - 1;
                else l = mid + 1;
            }
            ans = min(ans, i - l + 1);
        }

        return ans == INT_MAX ? 0 : ans;
    }
*/
};

int main() {
    while(true) {
        Solution solution;
        int target;
        cout << "target = ";
        cin >> target;
        string s;
        cout << "nums = ";
        cin >> s;

        auto nums = parse(s);
        cout << solution.minSubArrayLen(target, nums) << endl;
    }
    
    return 0;
}